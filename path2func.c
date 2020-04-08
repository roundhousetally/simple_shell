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
	struct stat sfile;
	pid_t pid;
	char *sl = "/";

	tokedpath = strtotok(path, ":");
	while (tokedpath[i] != NULL)
	{
		_strcat(tokedpath[i], sl);
		_strcat(tokedpath[i], s[0]);
		if (stat(tokedpath[i], &sfile) != -1)
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
				printf("fork failure");
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
