#include<stdio.h>

int main()
{
	int a = 10;
	int b = 20;

	int c = add(a,b);
	int d = sub(a,b);

	printf("\n %d + %d = %d", a, b, c);
	printf("\n %d - %d = %d", b, a, d);

	return 0;
}

