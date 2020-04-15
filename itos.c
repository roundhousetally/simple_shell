#include "pieshell.h"

/**
 * itos_helper - Helps ito
 * @num: The number to use
 * Return: The desired number
 */

int itos_helper(int num)
{
	int n;

	if (num < 0)
	{
		if (num != -2147483648)
			n = (num * -1);
		else
			n = num;
	}
	else
		n = num;
	return (n);
}

/**
 * itos - Turns an interger into a string
 * @num: The number to return
 *
 * Return: The return string
 */

char *itos(int num)
{
	int i;
	unsigned int rem, len = 0, n;
	char *s;

	if (num <= 0)
	{
		len++;
		if (num != -2147483648)
			n = (num * -1);
		else
			n = num;
	}
	else
		n = num;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		return (NULL);
	n = itos_helper(num);
	for (i = len - 1; i >= 0; i--)
	{
		rem = n % 10;
		n = n / 10;
		s[i] = rem + '0';
	}
	if (num < 0)
		s[0] = '-';
	s[len] = '\0';
	return (s);
}
