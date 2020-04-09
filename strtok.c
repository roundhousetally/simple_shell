#include "pieshell.h"


/**
 * strtotok - breaks a string into tokens and returns an array of each token.
 * @s: string to parse
 * @delim: delimiter
 * Return: array of tokens
 */

char **strtotok(char *s, const char *delim)
{
	char *token = NULL;
	char **alltokens = NULL;
	int i = 0, arraylength = 0;
	int slen = 0;
	char *ssave = NULL;
	slen = _strlen(s);

	ssave = malloc(sizeof(char) * (slen + 1));
	if (ssave == NULL)
	{
		return (0);
	}
	ssave = _strcpy(ssave, s);
	arraylength = _arraylength(ssave, delim);
	alltokens = malloc(sizeof(char *) * (arraylength + 2));
	token = strtok(s, delim);
	if (alltokens == NULL)
	{
		free(alltokens);
		free(ssave);
		return (0);
	}
	while (token != NULL)
	{
		printf("Token length: %d\n", _strlen(token));
		alltokens[i] = malloc(sizeof(unsigned long) * (_strlen(token) + 1));
		alltokens[i] = _strcpy(alltokens[i], token);
		printf("The token is: %s\nLength is: %d\nSize is: %lu\n", alltokens[i], _strlen(alltokens[i]), sizeof(alltokens[i]));
		if (alltokens[i] == NULL)
		{
			while (i >= 0)
			{
				free(alltokens[i]);
			}
			free(alltokens);
			free(ssave);
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

int _arraylength(char *string, const char *delim)
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
