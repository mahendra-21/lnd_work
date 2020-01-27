#include <stdio.h>
#define CAT(a) #a
int main()
{
	printf(CAT(print)"\n");
	return 0;
}
