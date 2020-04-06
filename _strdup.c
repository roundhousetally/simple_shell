#include "pieshell.h"

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
