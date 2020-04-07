#include "pieshell.h"

/**
 * moneyp - func to print the shell prompt
 * Return: void
 */

void moneyp(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
}
