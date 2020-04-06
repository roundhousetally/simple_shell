#include "pieshell.h"

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int nerds(char *string, char *delim);

char **splitstring(char *s, char *delim)
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
	ssave = _strcpy(ssave, s);
	arraylength = nerds(ssave, delim);
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
		alltokens[i] = malloc(sizeof(char *) * _strlen(token));
		if (alltokens[i] == NULL)
		{
			while (i >= 0)
			{
				free(alltokens[i]);
			}
			free(alltokens);
			return (0);
		}
		alltokens[i] = token;
		token = strtok(NULL, delim);
		i++;
	}
	alltokens[i] = NULL;
	free(ssave);
	return (alltokens);
}

int main(void)
{
	char test[] = "This is a test string";
	char *del = " ";
	int i = 0;
	char **result;

	result = splitstring(test, del);
	while(result[i] != NULL)
	{
		printf("Token: %s\n", result[i]);
		i++;
	}
	freestrtok(result);
	return (0);
}

int _strlen(char *s)
{
	int i = 0;

	while(s[i] != '\0')
		i++;
	return (i);
}

/**
 * _strcpy - Copies the string
 * @dest: Destination to copy
 * @src: Source to copy
 *
 * Return: Pointer to dest
 */

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		i++;
	}
	i++;
	i = 0;
	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

/**
 * nerds - Finds length of array to allocate
 * @string: The string to strtok
 * @delim: Delimiters to break up with
 *
 * Return: Length of array
 */

int nerds(char *string, char *delim)
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
