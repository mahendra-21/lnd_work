#include<stdio.h>
#include<stdlib.h>
#define BUF_MAX 256
char * str_tok (const char *buf, const char *delim)
{
	//Write your code here
	int i = 0;
	int j = 0;
	static int pos=0;
	char *token = NULL;
	token = (char *)malloc(BUF_MAX);
	/*
	 * Loop to skip the delimiter characters matched in buffer from start till 
	 * first non delimiter character 
	 */

	while(*(delim + i) != '\0'){
		if(*(buf + pos) == *(delim + i)){
			pos++;
			i = 0;
			continue;
		}
		i++;
	}
	
	/*If the buffer is parsed completely,return NULL as token */
	if(*(buf + pos) == '\0')
		return NULL;

	/* Loop parses the buffer and stores in token till it encounters delimiter and returns the token to the calling function */
	for(; *(buf+pos) != '\0';){
		for(i = 0; *(delim + i) != '\0'; i++){
			if(*(buf + pos) == *(delim + i)){
				*(token + j) = '\0';
					return token;
				}
			}
		*(token + j) = *(buf + pos);
		pos++;
		j++;
	} 
	
	*(token + j) = '\0';
	return token;
}
