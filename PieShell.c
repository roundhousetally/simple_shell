#include "pieshell.h"

/**
 * main - entry point of shell.
 * @argc: arg count
 * @argv: arg vars
 * @envp: environmental variables
 * Return: 0 on success
 */

int main(int argc, char *argv[], char **envp)
{
	ssize_t linesize;
	char *buf = NULL;
	size_t len = 0;

	if (argc == -1 || argv[0] == NULL)
		return (0);
	while (1)
	{
		printf("$ ");
		linesize = getline(&buf, &len, stdin);
		if (buf == EOF)
			printf("That's how that works\n");
		if (buf == NULL)
		{
			printf("Failed\n");
			free(buf);
			return (-1);
		}
		runit(buf, envp);
		free(buf);
		buf = NULL;
	}
	return (0);
}
