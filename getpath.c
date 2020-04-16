#include "pieshell.h"

/**
 * getpath - getting the path
 * @s: The arguments
 * @envp: Environment
 * @zero: Argv[0]
 * @count: Line count
 * Return: 0 on success, 1 for failure
 */

int getpath(char **s, char **envp, char *zero, int count)
{
	int i = 0, n = 0, flag;
	char *setp = "PATH=";
	char first[6];

	while (envp[i] != NULL)
	{
		n = 0;
		while (n <= 4)
		{
			first[n] = envp[i][n];
			n++;
		}
		first[n] = '\0';
		if (_strcmp(first, setp) == 0)
		{
			flag = comparepath(s, envp, i, n, zero, count);
		}
		i++;
	}
	if (flag == 0)
		return (0);
	if (flag == 126)
		return (126);
	return (1);
}

/**
 * comparepath - Compares the path
 * @s: Arguments
 * @envp: Environment variables
 * @i: A number
 * @n: - a Number
 * @zero: Argv[0]
 * @count: Line count
 * Return: 0 for success, 1 for failure
 */

int comparepath(char **s, char **envp, int i, int n, char *zero, int count)
{
	char *passedpath;
	int flag, newcount = 1;

	while (envp[i][n] != '\0')
	{
		newcount++;
		n++;
	}
	passedpath = malloc(sizeof(char *) * (newcount + 3));
	if (passedpath == NULL)
	{
		_puts("malloc error");
		return (0);
	}
	n = 5;
	newcount = 0;
	while (envp[i][n] != '\0')
	{ /** copies the path over */
		passedpath[newcount] = envp[i][n];
		newcount++;
		n++;
	}
	passedpath[newcount] = '\0';
	flag = pathhelp(s, passedpath, envp, zero, count);
	free(passedpath);
	return (flag);
}
