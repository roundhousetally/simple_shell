#include "pieshell.h"

int main(void)
{
	if (isatty(fileno(stdin)) == 1)
	{
		printf("Hey! That's how that works\n");
	}
	else
	{
		printf("No, that's not how that works.\n");
	}
	return (1);
}
