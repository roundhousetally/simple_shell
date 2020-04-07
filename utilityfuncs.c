#include "pieshell.h"

char *_strdup(char *str);
char *_strcpy(char *dest, char *src);

/**
 * _strcmp- compares two strings
 *@s1:first string
 *@s2:second string
 *Return: the differnce in strings
 */

int _strcmp(char *s1, char *s2)
{

	int i = 0;

	for (; s1[i] != '\0' && s2[i] != '\0';)
	{
		if (s1[i] == s2[i])
		{
			i++;
		}

		else
			break;
	}
	return (s1[i] - s2[i]);
}

/**
 *_strdup - returns a pointer to a newly allocated
 *space in memory that contains a copy of a string given as param.
 *
 *@str: the string as param to be copied
 *
 *Return: Null is str is null or if insufficient memory.
 *on success rturns a pointer to dup'd string
 */

char *_strdup(char *str)
{
	char *t;
	int i;
	int j;

	if (str == NULL)
	{
		return (NULL);
	}
	for (j = 0; str[j]; j++)
	{
		;
	}
	j++;

	t = malloc(j * sizeof(char));

	if (t == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < j; i++)
	{
		t[i] = str[i];
	}
	return (t);
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
