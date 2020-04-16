#include "pieshell.h"

/**
 * pathhelp - strtotok the path and execute
 * @s: Arguments entered
 * @path: The PATH
 * @envp: Environment variables
 * @zero: Argv[0]
 * @count: Counts the line
 * Return: 0 success, 1 for failure
 */

int pathhelp(char **s, char *path, char **envp, char *zero, int count)
{
	int i = 0, slen, pathreturn;
	char **tokedpath;
	char *save, *sl = "/";

	tokedpath = strtotok(path, ":");
	while (tokedpath[i] != NULL)
	{
		slen = _strlen(tokedpath[i]);
		save = _strdup(tokedpath[i]);
		if (s[0] == NULL)
		{
			free(save);
			freestrtok(tokedpath);
			return (1);
		}
		free(tokedpath[i]);
		tokedpath[i] = malloc(sizeof(char) * (slen + _strlen(s[0]) + 3));
		_strcpy(tokedpath[i], save);
		free(save);
		_strcat(tokedpath[i], sl);
		_strcat(tokedpath[i], s[0]);
		pathreturn = pathexec(s, tokedpath, envp, i, zero, count);
		if (pathreturn == -1)
			return (0);
		else if (pathreturn == 0)
			i++;
		else if (pathreturn == 126)
			return (126);
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
 * @z: Argv[0]
 * @c: Line count
 * Return: -1 for a failure, 0 for file not found, 1 for success
 */

int pathexec(char **s, char **tokedpath, char **envp, int i, char *z, int c)
{
	pid_t pid;
	struct stat status;

	if (stat(tokedpath[i], &status) == -1)
		return (0);
	if (access(tokedpath[i], X_OK) == -1)
	{
		denied(z, s[0], c);
		return (126);
	}
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
				_puts("Failed to execute");
				exit(1);
			}
			exit(0);
		}
		else if (pid == -1)
		{
			_puts("fork failure");
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
