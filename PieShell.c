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
	ssize_t linesize = 0;
	char *buf = NULL;
	size_t len = 0;

	if (argc == -1 || argv[0] == NULL)
		return (0);
	while (1)
	{
		moneyp();
		linesize = getline(&buf, &len, stdin);
		if (linesize == -1)
		{
			free(buf);
			return (-1);
		}
		if (buf == NULL)
		{
			free(buf);
			printf("Failed to store input\n");
			return (-1);
		}
		runit(&buf, envp);
		buf = NULL;
	}
	free(buf);
	fflush(stdout);
	return (0);
}
