#include "pieshell.h"

/**
 * getpath - getting the path
 *
 *
 *
 */

void getpath(char **s, char **envp)
{
	int i = 0, n = 0, count = 1;
	char *setp = "PATH=";
	char first[5];
	char *passedpath = NULL;
	int slen = 0;
	slen = _strlen(s[0]);

	first[0] = '\0';

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

			passedpath = malloc(sizeof(char) * (count + slen));
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
			pathhelp(s, passedpath, envp);
			free(passedpath);
		}
		i++;
	}
}
