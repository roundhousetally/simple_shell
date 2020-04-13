#include "pieshell.h"

/**
 * notfound - error printing for when a file is not found
 * @zero: argv[0]
 * @file: file unable to find
 * Return - void
 */

void notfound(char *zero, char *file)
{
	write(STDERR_FILENO, zero, _strlen(zero));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, file, _strlen(file));
	write(STDERR_FILENO, ": not found\n", 12);
}
