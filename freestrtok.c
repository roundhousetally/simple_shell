#include "pieshell.h"

/**
 * freestrtok - Frees a strtok array of words
 * @string: The string to free
 *
 * Return: Void
 */

void freestrtok(char **string)
{
	int i = 1;

	while (string[i] != NULL)
	{
		printf("Free string of %d is: %s\n", i, string[i]);
		i++;
	}
	i = 0;
	while (i < 6)
	{
		printf("Freeing %s\n", string[i]);
		free(string[i]);
		i++;
		printf("Now freeing: %s\n", string[i]);
	}
	free(string);
}
