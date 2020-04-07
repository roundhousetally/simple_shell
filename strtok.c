#include "pieshell.h"

int _arraylength(char *string, char *delim);

/**
 * strtotok - breaks a string into tokens and returns an array of each token.
 * @s: string to parse
 * @delim: delimiter
 * Return: array of tokens
 */

char **strtotok(char *s, char *delim)
{
	char *token;
	char **alltokens;
	int i = 0, arraylength;
	int slen = _strlen(s);
	char *ssave;

	ssave = malloc(sizeof(char) * (slen + 1));
	if (ssave == NULL)
	{
		free(ssave);
		return (0);
	}
	*ssave = _strcpy(ssave, s);
	arraylength = _arraylength(ssave, delim);
	alltokens = malloc(sizeof(char *) * (arraylength + 1));
	token = strtok(s, delim);
	if (alltokens == NULL)
	{
		free(alltokens);
		return (0);
	}
	while (token != NULL)
	{
		printf("Length of token: %d\n", (_strlen(token) + 1));
		alltokens[i] = _strdup(token);
		if (alltokens[i] == NULL)
		{
			while (i >= 0)
			{
				free(alltokens[i]);
			}
			free(alltokens);
			return (0);
		}
		token = strtok(NULL, delim);
		i++;
	}
	alltokens[i] = NULL;
	free(ssave);
	return (alltokens);
}

/**
 * _arraylength - Finds length of array to allocate
 * @string: The string to strtok
 * @delim: Delimiters to break up with
 *
 * Return: Length of array
 */

int _arraylength(char *string, char *delim)
{
	int count = 0;
	char *token;

	token = strtok(string, delim);
	while (token != NULL)
	{
		count++;
		token = strtok(NULL, delim);
	}
	count++;
	return (count);
}
