#include <header.h>

int validate_for_int(char *str) {

    if (NULL == str) {
        printf("String contains nothing\n");
        exit(0);
    }
    
    char *temp = str;

    if (('+' == *temp) || ('-' == *temp))     temp++;

    while (*temp) {
        
        if (('0' <= *temp) && ('9' >= *temp)) {
            temp++;
        } else if ('\n' == *temp) {
            *temp = *(temp + 1); 
            continue;
        } else {
            printf("Invali inputs\n");
            exit(0);
        }

    }

    return my_atoi(str);
}
