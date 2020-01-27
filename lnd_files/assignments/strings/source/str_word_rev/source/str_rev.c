/* Function for string reverse */
#include "header.h"

void my_strrev(char *str, int len, int start) {

    char temp = NULL;

    for (len = len - 1; len > start; start++, --len) {
        temp = str[start]; 
        str[start] = str[len];
        str[len] = temp;
    }

}
