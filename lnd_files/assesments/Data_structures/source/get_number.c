#include "header.h"

int get_number(void)
{
    char *str = (char *)malloc(SIZE * sizeof(char)); // allocating size

    if (NULL == str) { // checking wheather size is allocated or not
        printf("malloc failed to allocated size to str\n");
        exit(0);
    }

    fgets(str, SIZE, stdin); // To get the raw data from the standard input     buffer
     __fpurge(stdin); // To clear the data in stdin buffer

    if (('\0' == *str) || ('\n' == *str)) { // checking if user data is give    n 
        // or not
        printf("fgets failed to read the data from user\n");
        exit(0);
    }
    //    free(str);
    return validation(str); // calling the validation function
}
