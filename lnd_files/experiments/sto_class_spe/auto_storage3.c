#include <stdio.h>
void fun(register int );
int main()
{
    register int num0 = 10;
    register int num1 = 20;
    register int num2 = 30;
    register int num3 = 40;
    register int num4 = 50;
    register int num5 = 60;
    register int num6 = 70;
    register int num7 = 80;
	fun(num0);
	printf("number = %d\n",num1);
	printf("number = %d\n",num2);
	printf("number = %d\n",num3);
	printf("number = %d\n",num4);
	printf("number = %d\n",num5);
	printf("number = %d\n",num6);
	printf("number = %d\n",num7);
	return 0;
}
void fun(register int num)
{
	printf("number = %d\n",num);
}
