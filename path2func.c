#include "pieshell.h"

/**
 * pathhelp - strtotok the path and execute
 *
 *
 *
 */

void pathhelp(char **s, char *path, char **envp)
{
	int i = 0;
	char **tokedpath;
	pid_t pid;
	char *sl = "/";
	int slen;
	char *save;
	char *colon = ":";

	printf("Path is: %s\n", path);
	tokedpath = strtotok(path, colon);
	while (tokedpath[i] != NULL)
	{
		slen = _strlen(tokedpath[i]);
		save = _strdup(tokedpath[i]);
		tokedpath[i] = malloc(sizeof(char) * (slen + _strlen(s[0]) + 3));
		_strcpy(tokedpath[i], save);
		free(save);
		_strcat(tokedpath[i], sl);
		_strcat(tokedpath[i], s[0]);
		if (access(tokedpath[i], X_OK) != -1)
		{
			s[0] = NULL;
			s[0] = _strdup(tokedpath[i]);
		     	pid = fork();
	     		if (pid == 0)
	   		{
				if ((execve(s[0], s, envp) == -1))
				{
					freestrtok(tokedpath);
					printf("Failed to execute\n");
					return;
				}
			}
			else if (pid == -1)
			{
				printf("fork failure\n");
				freestrtok(tokedpath);
				return;
			}
			else
			{
				wait(NULL);
				freestrtok(tokedpath);
				return;
			}
		}
		i++;
	}
	freestrtok(tokedpath);
	printf("File not found\n");
}
