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
	char first[6];
	char *passedpath = NULL;

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
			printf("Count: %d\nStrlen: %d\n", count, (_strlen(envp[i]) - 5));
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
			pathhelp(s, passedpath, envp);
			free(passedpath);
		}
		i++;
	}
}
