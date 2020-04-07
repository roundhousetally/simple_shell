#include "pieshell.h"

int main(void)
{
	char *test = "This is a test string";
	int words;

	words = _strtok(test, " ");
	printf("String: %s\nWords: %d\n", test, words);
	return (0);
}
