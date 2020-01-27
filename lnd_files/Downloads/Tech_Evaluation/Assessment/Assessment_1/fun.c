/* In this program if user gives any in valid inputs while taking inputs
   at the time program is terminating by using exit(0) function */

#include <stdio.h>
#include <stdlib.h>
//#include <stdio_ext.h>

#define SIZE 128 // macro for defing the size of the string
#define RETURN -1 // macro for returning the value -1
#define MAX_INT 4294967295U // defining macro for max unsigned int range
#define NBITS_MAX sizeof(int) * 8 // macro for max number of bits
#define POS_MAX  NBITS_MAX - 1 // macro for max position in bits of an number

unsigned int validation(char *string); // fun declaration for validating 
// the user data
unsigned int my_atoi(const char *string); // fun declaration for converting 
// string to integer number

/* Function for get the number from the user */
unsigned int get_number(void)
{
    char *str = (char *)malloc(SIZE * sizeof(char)); // allocating size

    if (NULL == str) { // checking wheather size is allocated or not
        printf("malloc failed to allocated size to str\n");
        exit(0);
    }

    fgets(str, SIZE, stdin); // To get the raw data from the standard input buffer
    //    __fpurge(stdin); // To clear the data in stdin buffer

    if (('\0' == *str) || ('\n' == *str)) { // checking if user data is given 
        // or not
        printf("fgets failed to read the data from user\n");
        exit(0);
    }
//    free(str);
    return validation(str); // calling the validation function
}

/* Validating the raw string given from the user */
unsigned int validation(char *string)
{

    if (NULL == string) { // checking if string having data or not
        printf("In validation function string is not recived\n");
        exit(0);
    }

    char *temp = string; // storing starting addr. of string into temp

    if ('+' == *string)// checking if first char is '+' incrementing the string
        string++; 

    if ('-' == *string) { // if first char is '-' throwing error message
        printf("In bit-wise operatoions on '-ve' numbers are not allowed\n");
        exit(0);
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

/* Function definition for converting string into a number */
unsigned int my_atoi(const char *str)
{
    if (NULL == str) { // checking if string having data or not
        printf("In my_atoi function string is not recived\n");
        exit(0);
    }

    unsigned long long int number = 0;

    if ('+' == *str) // ignoring the '+' character
        str++;

    while (*str) {
        /* converting the characters into number */
        number = number * 10 + (*str++ - 48); 
        /* if number is greater than MAX_INT range throwing an error */
        if (MAX_INT < number) {
            printf("Given more than the unsigned integer range\n");
            exit(0);
        }

    }

    return number; // returning the number
}

/* Function definition for by printing binary format of a number */
void print_binary(unsigned int number)
{
    int pos = (sizeof(int) * 8) - 1; // getting pos to start the loop

    for (; pos >= 0; --pos) {
        printf("%d", number >> pos & 1); // printing the bits on monitor

        if (0 == pos % 8) // giving spaces for every byete
            printf(" ");

    }

    printf("\n");    
}

/* function for inverting a given number from position pos to LSB side 
   nbits */
int invert(unsigned int number, unsigned int pos, unsigned int nbits)
{
    /* if the following both conditaions are failes 
       t returns -1 to main function */
    if ((pos >= nbits) && (pos < nbits))      return RETURN;

    if ((POS_MAX < pos) || (NBITS_MAX < nbits))     return RETURN;

    unsigned int mask = 0;

    /* creating mask for nbits from the given position */
    mask = ((1 << nbits) - 1) << (pos - nbits + 1);

    return number ^ mask; // exoring the mask with original number 
}
