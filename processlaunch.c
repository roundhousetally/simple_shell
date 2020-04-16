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
	if (args[0] == NULL)
	{
		freestrtok(args);
		return (1);
	}
	if (args[0][0] == '/')
	{
		return (runexec(args, envp, zero, count));
	}
	flag = getpath(args, envp, zero, count);
	if (flag == 1)
	{
		freestrtok(args);
		return (0);
	}
	if (flag == -1)
	{
		freestrtok(args);
		return (-1);
	}
	if (flag == 0)
		return (runexec(args, envp, zero, count));
	if (flag == 126)
	{
		freestrtok(args);
		return (126);
	}
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
	struct stat exists;

	pid = fork();
	if (pid == 0)
	{
		if (stat(args[0], &exists) < 0)
		{
			notfound(zero, args[0], count);
			freestrtok(args);
			exit(1);
		}
		if (access(args[0], X_OK) == 0 &&
		    ((args[0][0] == '.' && args[0][1] == '/') || args[0][0] == '/'))
		{
			execve(args[0], args, envp);
			freestrtok(args);
			exit(0);
		}
		else if (access(args[0], X_OK) == 0)
		{
			notfound(zero, args[0], count);
			freestrtok(args);
			exit(1);
		}
		else
		{
			denied(zero, args[0], count);
			freestrtok(args);
			exit(126);
		}
		exit(0);
	}
	return (pathexechelp(pid, args));
}

/**
 * pathexechelp - Literally just to keep the last function under 40 lines
 * @pid: Pid status
 * @args: Arguments
 * Return: Status
 */

int pathexechelp(pid_t pid, char **args)
{
	int status, exitstat;

	if (pid == -1)
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
		return (exitstat);
	}
	return (1);
}
