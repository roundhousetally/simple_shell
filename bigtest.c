#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void runit(const char *test);

int main(int argc, char *argv, char **envp)
{
	ssize_t linesize;
	char *buf = NULL;
	size_t len = 0;
	char *commands[3];
	char *envar[] = {"nothing", NULL};

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
		/*commands[0] = buf;*/
		commands[0] = ".";
		commands[1] = NULL;
		if (fork() == 0)
		{
			if (execve(buf, commands, envar) == -1)
				printf("Failed\n");
		}
		free(buf);
	}
	printf("Line size: %d", (int)linesize);
	return(0);
}

void runit(const char *test)
{
	char *argv[3];
	char *evars[] = {NULL};

	printf("%s\n", test);
	/*argv[0] = test;*/
	argv[0] = ".";
	argv[1] = NULL;
	if (fork() == 0)
	{
		if (execve((char *)test, argv, evars) == -1)
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

