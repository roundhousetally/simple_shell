#include "pieshell.h"

/**
 * _strtok - Works like strtok but not destructive
 * @string: String to divide up
 * @spacers: Spacers to use (Like a space or a colon)
 *
 * Return: An array of the individual segments
 */

int _strtok(char *string, char *spacers)
{
	int i = 0, n = 0, wordcount = 0, secondflag = 0;

	while (string[i] != '\0')
	{
		while (spacers[n] != '\0' && i != 0)
		{
			if (string[i] == spacers[n])
			{
				wordcount++;
				while (string[i] != '\0')
				{
					secondflag = 0;
					n = 0;
					while (spacers[n] != '\0')
					{
					if (string[i] == spacers[n])
					{
					secondflag = 1;
					i++;
					}
					}
					if (secondflag == 0)
						i++;
				}
			}
			n++;
		}
		if (secondflag == 0)
			i++;
	}
	return (wordcount);
}
