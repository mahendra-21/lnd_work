#include "header.h"

/* Validating the raw string given from the user */
int validation(char *string)
{

    if (NULL == string) { // checking if string having data or not
        printf("In validation function string is not recived\n");
        exit(0);
    }

    char *temp = string; // storing starting addr. of string into temp

    if ('+' == *string || '-' == *string) {
        // checking if first char is '+' incrementing the string
        string++; 
    }

    while (*string) {
        /* if string is having otherthan numbers it's throwing error message */
        if (('0' <= *string) && ('9' >= *string)) {
            string++;
        } else {
            /* if in string '\n' is present removing '\n' character */
            if ('\n' == *string) {
                *string = *(string + 1);
                continue;
            }

            printf("***** Invalid inputs *****\n");
            exit(0);
        }

    }

    return my_atoi(temp); // calling own atoi function
}

