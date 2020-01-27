/* Function to read input using fgets */
#include "../HEADER/header.h"
char *read_input(char *input)
{

	__fpurge(stdin);
	if (NULL == (fgets(input, MAX_BUF, stdin))) {
		printf("Failure in read_input\n");
		exit(EXIT_FAILURE);
	}

	return input;
}
