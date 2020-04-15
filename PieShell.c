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
	int flagexit = 0;

	if (argc == -1 || argv[0] == NULL)
		return (0);
	while (flagexit == 0)
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
			_puts("Failed to store input");
			return (-1);
		}
		flagexit = builtins(buf, envp, argv[0]);
		buf = NULL;
	}
	free(buf);
	return (0);
}

/**
 * builtins - Builtins and execution
 * @buf: Buffer
 * @envp: Environment variables
 * @filename: Name of the executed file
 *
 * Return: 1 for exit, 0 for continue
 */

int builtins(char *buf, char **envp, char *filename)
{
	int flagexit = 0;
	int flag = 0;
	char *nomas = "exit\n", **env, *vars = "env\n";

	if (_strcmp(buf, nomas) == 0)
	{
		free(buf);
		flagexit = 1;
	}
	if (flagexit == 0 && _strcmp(buf, vars) == 0)
	{
		for (env = envp; *env; ++env)
		{
			_puts(*env);
		}
		free(buf);
		flag = 1;
		buf = NULL;
	}
	if (flagexit == 0 && flag == 0 && buf != NULL && (_strcmp(buf, "\n") != 0))
	{
		runit(&buf, envp, filename);
		flag = 1;
	}
	else if (flagexit == 0 && flag == 0 && _strcmp(buf, "\n") == 0)
	{
		free(buf);
		flagexit = 0;
	}
	return (flagexit);
}
