#include "pieshell.h"

/**
 *_strlen - calculates the length of a string
 *@s: the string to be counted
 * Return: the length of the string
 * On error, -1 is returned, and errno is set appropriately.
 */

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;
	return (i);
}
