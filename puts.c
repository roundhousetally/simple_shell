#include "pieshell.h"

/**
 *_puts - prints a string followed by a new line
 *@str: the string to be printed
 * Return: On success 1.
 */

void _puts(char *str)
{
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	_putchar('\n');
}
