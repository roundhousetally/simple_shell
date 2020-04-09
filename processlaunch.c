#include "pieshell.h"

/**
 * runit - starts shell processing
 * @test: pointer to cmd string
 * @envp: env vars
 * Return: void
 */

void runit(char **test, char **envp)
{
	int i = 0;
	pid_t pid = 0;
	char **args = NULL;
	char *detest = *test;
	struct stat sfile;

	while (detest[i] != '\n')
		i++;
	detest[i] = '\0';
	args = strtotok(detest, " ");
	free(detest);
	if ((stat(args[0], &sfile) == -1))
	{
		getpath(args, envp);
		freestrtok(args);
		return;
	}
	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, envp) == -1)
		{
			freestrtok(args);
			printf("File not found\n");
			return;
		}
	}
	else if (pid == -1)
	{
		freestrtok(args);
		printf("Process failed\n");
		return;
	}
	else
	{
		freestrtok(args);
		wait(NULL);
	}
	free(test);
}
