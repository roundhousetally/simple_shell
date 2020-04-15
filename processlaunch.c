#include "pieshell.h"

/**
 * runit - starts shell processing
 * @test: pointer to cmd string
 * @envp: env vars
 * @zero: error code
 * @count: Counts the number of times the shell is run
 * Return: -1 for fail
 */

int runit(char **test, char **envp, char *zero, int count)
{
	int i = 0, flag = 0;
	char **args = NULL;
	char *detest = *test;

	while (detest[i] != '\n')
		i++;
	detest[i] = '\0';
	args = strtotok(detest, " ");
	free(detest);
	flag = getpath(args, envp);
	if (flag == 1)
	{
		freestrtok(args);
		return (0);
	}
	if (flag == -1)
		return (-1);
	if (flag == 0)
		return (runexec(args, envp, zero, count));
	return (1);
}

/**
 * runexec - Runs some stuff from runit
 * @args: Args
 * @envp: Environment variables
 * @zero: Argv[0]
 * @count: Number of times program is run
 * Return: The result
 */

int runexec(char **args, char **envp, char *zero, int count)
{
	pid_t pid;
	int status, exitstat;

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			notfound(zero, args[0], count);
			freestrtok(args);
			exit(1);
		}
		exit(0);
	}
	else if (pid == -1)
	{
		freestrtok(args);
		_puts("Process failed");
		return (1);
	}
	else
	{
		freestrtok(args);
		waitpid(pid, &status, 0);
		exitstat = WEXITSTATUS(status);
		if (exitstat == 1)
			return (1);
		return (0);
	}
	return (1);
}
