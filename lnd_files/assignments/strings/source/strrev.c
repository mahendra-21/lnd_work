/* reverse a given string */

#include <string_header.h>

void my_strrev(char *str) {

    char temp = NULL;

    int start = 0;

    int len = 0;

    for (; str[len]; len++);

    for (len = len - 1; len > start; start++, --len) {

        temp = str[start]; 

        str[start] = str[len];

        str[len] = temp;

    }

}
