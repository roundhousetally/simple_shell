#include "pieshell.h"

int _putchar(char c);
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
	_putchar(10);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
