#include "pieshell.h"

/**
 * pathhelp - strtotok the path and execute
 * @s: Arguments entered
 * @path: The PATH
 * @envp: Environment variables
 * @zero: argv[0]
 * Return: 0 for a fail, 1 for success
 */

int pathhelp(char **s, char *path, char **envp)
{
	int i = 0, slen, pathreturn;
	char **tokedpath;
	char *save, *sl = "/";

	tokedpath = strtotok(path, ":");
	while (tokedpath[i] != NULL)
	{
		slen = _strlen(tokedpath[i]);
		save = _strdup(tokedpath[i]);
		free(tokedpath[i]);
		tokedpath[i] = malloc(sizeof(char) * (slen + _strlen(s[0]) + 3));
		_strcpy(tokedpath[i], save);
		free(save);
		_strcat(tokedpath[i], sl);
		_strcat(tokedpath[i], s[0]);
		pathreturn = pathexec(s, tokedpath, envp, i);
		if (pathreturn == -1)
			return (0);
		else if (pathreturn == 0)
			i++;
		else
			return (1);
	}
	freestrtok(tokedpath);
	return (0);
}

/**
 * pathexec - Executes a command from the path
 * @s: The command, and arguments
 * @tokedpath: The path in tokens
 * @envp: Environment varaibles
 * @i: The index of tokedapth
 *
 * Return: -1 for a failure, 0 for file not found, 1 for success
 */

int pathexec(char **s, char **tokedpath, char **envp, int i)
{
	pid_t pid;

	if (access(tokedpath[i], X_OK) != -1)
	{
		free(s[0]);
		s[0] = _strdup(tokedpath[i]);
		pid = fork();
		if (pid == 0)
		{
			if ((execve(s[0], s, envp) == -1))
			{
				freestrtok(tokedpath);
				printf("Failed to execute\n");
				return (-1);
			}
		}
		else if (pid == -1)
		{
			printf("fork failure\n");
			freestrtok(tokedpath);
			return (-1);
		}
		else
		{
			wait(NULL);
			freestrtok(tokedpath);
			return (1);
		}
	}
	return (0);
}
