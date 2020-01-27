#include <stdio.h>
#define SIZE 100
int main()
{
	char _str [SIZE];
	printf ("Enter A String:");
	fgets (_str, SIZE, stdin);
	fflush (stdin);
	printf (" %s \n", _str);
	return 0;
}
