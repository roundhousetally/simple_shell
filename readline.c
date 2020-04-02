#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	ssize_t linesize;
	char *buf = NULL;
	size_t len = 0;

	printf("$ ");
	linesize = getline(&buf, &len, stdin);
	if (buf == NULL)
	{
		printf("Failed\n");
		free(buf);
		return(-1);
	}
	printf("%s - %u\n", buf, (unsigned int)linesize);
	free(buf);
	return (1);
}
