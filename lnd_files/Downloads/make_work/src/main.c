#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#include "header.h"
int main( void )
{
	int a = 0;
	int b = 0;
		
	char *str = NULL;
	
	if(NULL == (str = (char*)malloc(sizeof(char)*MAX))){
		printf("Malloc failed\n");
		exit(EXIT_FAILURE);
	}
	
	printf("Enter the value of a\n");
	fgets(str,MAX,stdin);
	
	a = atoi(str);
	
	fflush(stdin);

	printf("Enter the value of b\n");
	fgets(str,MAX,stdin);
	
	b = atoi(str);
	
	
	printf("Sum of %d and %d is %d \n",a,b,(add(a,b)));
	printf("diff of %d and %d is %d \n",a,b,(sub(a,b)));
	printf("mul of %d and %d is %d \n",a,b,(mul(a,b)));
	printf("div of %d and %d is %d \n",a,b,(divide(a,b)));
		
	return 0;
}

	
