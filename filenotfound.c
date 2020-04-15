#include "pieshell.h"

/**
 * notfound - error printing for when a file is not found
 * @zero: argv[0]
 * @file: file unable to find
 * @count: Number of times executed in main loop
 * Return - void
 */

void notfound(char *zero, char *file, int count)
{
	char *num = itos(count);

	write(STDERR_FILENO, zero, _strlen(zero));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, num, _strlen(num));
	free(num);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, file, _strlen(file));
	write(STDERR_FILENO, ": not found\n", 12);
}
