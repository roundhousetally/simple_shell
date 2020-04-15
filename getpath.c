#include "pieshell.h"

/**
 * getpath - getting the path
 * @s: The arguments
 * @envp: Environment
 *
 * Return: 0 on success, 1 for failure
 */

int getpath(char **s, char **envp)
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
			flag = comparepath(s, envp, i, n);
		}
		i++;
	}
	if (flag == 0)
		return (0); /** is this correct? */
	return (1);
}

/**
 * comparepath - Compares the path
 * @s: Arguments
 * @envp: Environment variables
 * @i: A number
 * @n: - a Number
 * Return: 0 for success, 1 for failure
 */

int comparepath(char **s, char **envp, int i, int n)
{
	char *passedpath;
	int flag, count = 1;

	while (envp[i][n] != '\0')
	{
		count++;
		n++;
	}
	passedpath = malloc(sizeof(char *) * (count + 3));
	if (passedpath == NULL)
	{
		_puts("malloc error");
		return (0);
	}
	n = 5;
	count = 0;
	while (envp[i][n] != '\0')
	{
		passedpath[count] = envp[i][n];
		count++;
		n++;
	}
	passedpath[count] = '\0';
	flag = pathhelp(s, passedpath, envp);
	free(passedpath);
	return (flag); /** is this going to be 0 ? */
}
