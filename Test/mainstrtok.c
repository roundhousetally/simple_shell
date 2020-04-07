#include "pieshell.h"

int main(void)
{
	char test[] = "This is a test string";
	char *del = " ";
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
