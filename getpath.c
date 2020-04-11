#include "pieshell.h"

/**
 * getpath - getting the path
 * @s: The arguments
 * @envp: Environment
 *
 */

void getpath(char **s, char **envp, char *zero)
{
	int i = 0, n = 0, count = 1;
	char *setp = "PATH=", *passedpath;
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
			while (envp[i][n] != '\0')
			{
				count++;
				n++;
			}
			passedpath = malloc(sizeof(char *) * (count + 3));
			if (passedpath == NULL)
			{
				printf("malloc error\n");
				return;
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
			pathhelp(s, passedpath, envp, zero);
			free(passedpath);
		}
		i++;
	}
}
