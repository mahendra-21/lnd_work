#include <stdio.h>
#define xcat(x,y) x##y
#define xxcat(x,y) cat(x,y)
int main()
{
	int a = (xcat(xcat(3, 0), xcat(2, 0)));
	printf("a");	
	return 0;
}



