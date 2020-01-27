#include <stdio.h>
#define MAX 10
int main()
{
	printf("%d\n", MAX(2, 3));
	return 0;
}
int MAX(int num1, int num2)
{
	int num;
	num = (num1 > num2)? num1: num2;
	return num;
}
