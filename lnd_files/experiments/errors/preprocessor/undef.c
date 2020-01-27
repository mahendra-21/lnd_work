#include <stdio.h>

#define MAHI 100
int main()
{
	#if MAHI == 100
		printf("IN if ---> %d \n", MAHI);
	#endif
	return 0;
}

