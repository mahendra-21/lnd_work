#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>
#include<ctype.h>
#define BUF_MAX 256

char *str_tok( const char *buf,const char *delim );
int main( void ) 
{
	char *sbuf = NULL;
	char *dbuf = NULL;
	char *token = NULL;

	sbuf = malloc ( BUF_MAX);
	dbuf = malloc ( BUF_MAX);
	token = malloc ( BUF_MAX);
	fgets(sbuf , BUF_MAX, stdin);
	fgets(dbuf, BUF_MAX, stdin);

	token = str_tok(sbuf,dbuf);
	if(token == NULL)
		printf("0\n");
	else {
		printf("%s\n",token);
		while(token != NULL){
			token = str_tok(sbuf,dbuf);
			if(token != NULL)
				printf("%s\n",token);
		}
	}
	return 0;
}
