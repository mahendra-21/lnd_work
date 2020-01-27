#include<stdio.h>
int main()
{
	int num;
	int start;
	printf("Enter a number to check prime:\n");
	scanf("%d",&num);
	for(start=2;start<num;start++)
		if(num%start==0)
			break;
	if(num==start)
		printf("given number is a prime number\n");
	else
		printf("given number is not a prime number\n");
	return 0;
}
