#include "pieshell.h"

/**
 * runit - starts shell processing
 * @test: pointer to cmd string
 * @envp: env vars
 * @zero: error code
 * Return: -1 for fail
 */

int runit(char **test, char **envp, char *zero)
{
	int i = 0, flag = 0, status;
	pid_t pid;
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
		pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			notfound(zero, args[0]);
			freestrtok(args);
			exit(1);
		}
		exit(0);
	}
	else if (pid == -1)
	{
		freestrtok(args);
		_puts("Process failed");
		return (-1);
	}
	else
	{
		freestrtok(args);
		waitpid(pid, &status, 0);
		if (WEXITSTATUS(status) == 1)
			return (-1);
		return (0);
	}
}
