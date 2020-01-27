#include <stdio.h>
#define FUN(a, b) printf(#a"=%d\n", b)
int main()
{
	int a = 5;
	char str[] = "give number";
	FUN(str, a);
	return 0;
}
