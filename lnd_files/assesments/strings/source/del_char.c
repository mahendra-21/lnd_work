/* function for deleting consicutive repeated characters in a string */

#include <header.h>

void *del_char(char *str) { 

    if (NULL == *str) {
        return 0; /*returning '0'(NULL) if in string having null*/
    }

    char *temp = str;

    while (*str) {
       
       *temp = *str++;

       if (*temp != *str) {
            temp++;
       } 

    }

    *temp = '\0';

    return 1; // returning one upon success
}
