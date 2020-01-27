#include <stdio.h>
int sum(int num1, int num2);
int main()
{
 	int number1;
	int number2;
	int result;
	
	printf("enter the two numbers:\n");
	scanf("%d %d\n", &number1, &number2);
	
	result = sum(number1, number2);

	printf("sum = %d\n", result);

	return 0;
}

int sum(int a, int b)
{
	int ret;
	
	return ret = a + b;
}
