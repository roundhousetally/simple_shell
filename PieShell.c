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
	struct stat st;

	if (argc == -1 || argv[0] == NULL)
		return (0);
	if (stat(argv[1], &st) == 0)
		printf("AC FILE FOUND\n");
	while (1)
	{
		moneyp();
		linesize = getline(&buf, &len, stdin);
		if (buf == NULL)
		{
			printf("Failed\n");
			free(buf);
			return (-1);
		}
		if (stat(buf, &st) == 0)
			printf("File is found\n");
		runit(buf, envp);
		free(buf);
		buf = NULL;
	}
	printf("Line size: %d", (int)linesize);
	return (0);
}
