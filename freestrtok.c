#include "pieshell.h"

/**
 * freestrtok - Frees a strtok array of words
 * @string: The string to free
 *
 * Return: Void
 */

void freestrtok(char **string)
{
	int i = 0;

	while (string[i] != NULL)
	{
		free(string[i]);
		i++;
	}
	free(string);
}
