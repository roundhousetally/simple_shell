#include "pieshell.h"

int main(void)
{
	char test[] = "/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games";
	char *del = ":";
	int i = 0;
	char **result;

	result = strtotok(test, del);
	while(result[i] != NULL)
	{
		printf("Token: %s\n", result[i]);
		i++;
	}
	freestrtok(result);
	return (0);
}
