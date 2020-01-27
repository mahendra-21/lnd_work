#include "header.h"

int main(void)
{
    char *str = (char *) malloc(SIZE * sizeof(char)); 

    if (NULL == str) {
        printf("Malloc failed to allocate size\n");
        return 0;
    }

    printf("Enter the string: ");
    fgets(str, SIZE, stdin);

    if (('\0' == *str) || ('\n' == *str)) {
        printf("fgets() failed to read data from stdin\n");
        return 0;
    } else {
        char *temp = str;

        while (*temp) {
            if ('\n' == *temp)
                *temp = *(temp + 1);
            temp++;
        }

    }

    char *str1 = strin_out(str);
    printf("final string = %s\n", str1);
    return 0;
}
