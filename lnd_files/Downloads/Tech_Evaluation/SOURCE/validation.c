/* Includes function for validating inputs */
#include "../HEADER/header.h"

/*Function to validate entered input string is valid or not */
int intval(char *str)
{

	if(strlen(str) == 1)
		return 1;

	for(; isspace(*str);str++);

	if(*str == '+' || *str == '-')
		str++;

	for(; *str != '\n'; str++){
		if(!isdigit(*str)){
			if(isspace(*str)){
				break;
			}
			return 1;
		}
	}

	for(; *str != '\n'; str++) {
		if(!isspace(*str))
			return 1;
	}

	*str = '\0';
	return 0;
}

/*Function to validate entered input string for file name */
int file_name_val(char *str)
{
	if(strlen(str) == 1)
		return 1;

	for(; *str!='\n'; str++) {
		if( *str < 48 || ((*str > 57) && (*str < 95))
					|| ((*str > 95) && (*str < 97)) || *str > 123 ) {
			return 1;
		}
	}
	
	*str = '\0';
	return 0;
}

/*Function to validate entered input string is valid or not */
int strval(char *str)
{
    if( strlen(str) == 1 )
        return 1;

    for(; *str!='\n'; str++) {
        if( *str < 32)
		    return 1;
    }

    *str = '\0';
    return 0;
}

/* Function to remove new line character from the string at the end*/
int rm_new_line(char *str)
{
	while( *str != '\n')
		str++;
	*str = '\0';
	return 0;
}
