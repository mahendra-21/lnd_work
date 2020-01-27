#include <stdio.h>
#include <stdlib.h>
#define SIZE 15
int main (int argc, char **argv)
{
	FILE *fp;
	char s[SIZE];
	if (argc != 2)
	{
		printf("Usage: ./exe_fname fname\n");
		exit (0);
	} 
	fp = fopen ( argv [1], "r");
	if (fp == 0)
	{
		printf ("File not present\n");
		return 0;
	}
	fgets (s, SIZE, fp);
	printf ("string is  %s \n ",s);
	return 0;
}
	
