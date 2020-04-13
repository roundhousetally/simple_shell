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
	char *nomas = "exit\n", *vars = "env\n";
	char **env;
	int flag = 0;

	if (argc == -1 || argv[0] == NULL)
		return (0);
	while (1)
	{
		flag = 0;
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
			flag = 1;
			buf = NULL;
		}
		if (flag == 0 && buf != NULL && (_strcmp(buf, "\n") != 0))
		{
			runit(&buf, envp, argv[0]);
			flag = 1;
		}
		else if (flag == 0 && _strcmp(buf, "\n") == 0)
			continue;
		buf = NULL;
	}
	free(buf);
	return (0);
}
