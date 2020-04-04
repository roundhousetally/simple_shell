#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void runit(char *test, char **envp);

int main(int argc, char *argv[], char **envp)
{
	ssize_t linesize;
	char *buf = NULL;
	size_t len = 0;
	struct stat st;

	if (argc == -1 || argv[0] == NULL)
		return (0);
	if (stat(argv[1], &st) == 0)
		printf("AC FILE FOUND\n");
	while (1)
	{
		printf("Entering the shell...\n");
		printf("$ ");
		linesize = getline(&buf, &len, stdin);
		if (buf == NULL)
		{
			printf("Failed\n");
			free(buf);
			return(-1);
		}
		if (stat(buf, &st) == 0)
			printf("File is found\n");
		runit(buf, envp);
		free(buf);
		buf = NULL;
	}
	printf("Line size: %d", (int)linesize);
	return(0);
}

void runit(char *test, char **envp)
{
	char *argv[3];
	struct stat st;
	int i = 0;

	while (test[i] != '\n')
		i++;
	test[i] = '\0';
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

