#include <stdio.h>
#define MACRO(num,str)  do{\
						printf("%d",num);\
						printf("is");\
						printf("%s",str);\
						printf("\n");\
					   }while (0)
int main()
{
	int num=0;
	printf("enter number:\n");
	scanf("%d",&num);
	if (num & 1)
		MACRO(num,"odd");
	else
		MACRO(num, "even");
	return 0;
}
