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
	struct stat st;
	int i = 0;

	while (test[i] != '\n')
		i++;
	test[i] = '\0';
	printf("Buffer is: %s\n", test);
	printf("%c", test[i]);
	printf("The buffer is: %s\n", test);
	if (stat(test, &st) == 0)
		printf("File found!\n");
	else
		printf("File not found\n");
	argv[0] = test;
	argv[1] = ".";
	argv[2] = NULL;
	if (fork() == 0)
	{
		if (execve(argv[0], argv, envp) == -1)
		{
			printf("We done didly fucked up\n");
		}
	}
	else
	{
		wait(NULL);
		printf("Something went very well\n");
	}
}
