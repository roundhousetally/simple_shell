#include "pieshell.h"

/**
 * runit - starts shell processing
 * @test: pointer to cmd string
 * @envp: env vars
 * @zero: error code
 * Return: void
 */

void runit(char **test, char **envp, char *zero)
{
	int i = 0, flag = 0;
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
		return;
	}
	if (flag == 0)
		pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			notfound(zero, args[0]);
			freestrtok(args);
			return;
		}
	}
	else if (pid == -1)
	{
		freestrtok(args);
		_puts("Process failed\n");
		return;
	}
	else
	{
		freestrtok(args);
		wait(NULL);
	}
}
