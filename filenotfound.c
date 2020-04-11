#include "pieshell.h"

void notfound(char *zero, char *file)
{
	write(STDERR_FILENO, zero, _strlen(zero));
	write(STDERR_FILENO, ": 1: ", 5);
	write(STDERR_FILENO, file, _strlen(file));
	write(STDERR_FILENO, ": not found\n", 12);
}
