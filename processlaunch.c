#include "pieshell.h"

/**
 * runit - starts shell processing
 * @test: pointer to cmd string
 * @envp: env vars
 * Return: void
 */

void runit(char *test, char **envp)
{
	char *argv[3];
	int i = 0;

	while (test[i] != '\n')
		i++;
	test[i] = '\0';
	argv[0] = test;
	argv[1] = ".";
	argv[2] = NULL;
	if (fork() == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			printf("File not found\n");
			return;
		}
	}
}
