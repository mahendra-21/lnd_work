/* Write a function invert (x,p,n) that returns x with n bits that begin at position p inverted, leaving others unchanged.

   Example:
   input : 178
   5
   5
   
   Output :
   140
   
   Explanation : 
   Starting from 5th bit towards LSB invert the 5 bits of variable x and 
   retain the other bit values as it is.
   
   Upon successful execution function should return the result or 
   function should return -1.
 */

#include <stdio.h>

#define TEST -1 // Macro for to check the return value of invert function

/* Function declaration for the inverting the bits function */
unsigned int invert(unsigned int number, unsigned int pos, unsigned int nbits);

/* function declation for printing the binary format of the number */
void print_binary(unsigned int number);

/* Function declaration for to get the number from the user */
unsigned int get_number(void);

int main(void)
{
    /* Taking three variables for inverting the number from given position to
       nbits from LSB side of a number */
    unsigned int number = 0;
    unsigned int pos = 0;
    unsigned int nbits = 0;

    printf("\nEnter the Number: ");
    number = get_number(); // getting number from user to invert the nbits
                           // from the given position
    printf("\nEnter the Position: ");
    pos = get_number(); // getting position from the user

    printf("\nEnter the No of bits: ");
    nbits = get_number(); // geting no of bits to invert in the number from user

    printf("\nBefore number is: ");
    print_binary(number); // printing the binary format of the number
                          // before calling invert function

    number = invert(number, pos, nbits); // Calling the inverting function

    if (TEST == number) { // If invert function return -1 that function is failed
        printf("Function is failed\n"); 
    } else {
        printf("After number is : ");
        print_binary(number); // printing the binary format of the number
                              // after called invert function
    }

    return 0;
}
