#include "pieshell.h"

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
