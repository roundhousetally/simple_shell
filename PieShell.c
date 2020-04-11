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
	char *nomas = "exit\n";
	char *vars = "env\n";
	char **env;

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
			perror("Failed to store input\n");
			return (-1);
		}
		if (_strcmp(buf, nomas) == 0)
			break;
		if (_strcmp(buf, vars) == 0)
		{
			for (env = envp; *env; ++env)
			{
				_puts(*env);
			}
			free(buf);
			buf = NULL;
		}
		if (buf != NULL)
			runit(&buf, envp, argv[0]);
		buf = NULL;
	}
	free(buf);
	return (0);
}
