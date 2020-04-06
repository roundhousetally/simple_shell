#include "pieshell.h"
#include <limits.h>

int main(void)
{
	char cwd[PATH_MAX];

	if (getcwd(cwd, sizeof(cwd)) != NULL)
	{
		printf("Current working directory: %s\n", cwd);
		chdir("..");
		printf("Not anymore!\nNew directory: %s\n", getcwd(cwd, sizeof(cwd)));
	}
	else
	{
		printf("getcwd() fail\n");
		return (-1);
	}
	return(42);
}
