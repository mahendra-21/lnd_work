#include "header.h"

/* Function definition for converting string into a number */
int my_atoi(const char *str)
{
    if (NULL == str) { // checking if string having data or not
        printf("In my_atoi function string is not recived\n");
        exit(0);
    }

    unsigned long long int number = 0;
    char ch;

    if ('+' == *str || '-' == *str)  // ignoring the '+' character
        ch = *str ++;

    while (*str) {
        /* converting the characters into number */
        number = number * 10 + (*str++ - 48); 
        /* if number is greater than MAX_INT range throwing an error */
        if (MAX_INT < number) {
            printf("Given more than the unsigned integer range\n");
            exit(0);
        }

    }
    
    if ('-' == ch)  number = -number;


    return number; // returning the number
}

