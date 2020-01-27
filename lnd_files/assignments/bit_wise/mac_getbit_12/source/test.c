/* 
 * Write a macro getbits (x,p,n) that retuns (left adjusted) 
 * n-bit field of x that begins at position p.
 */

#include <header.h>

int main()
{
    char r_data1[SIZE] = {0};
    char bit_data[SIZE] = {0};
    char pos_data[SIZE] = {0};

    char buff1[SIZE] = {0};
    char bit_buff[SIZE] = {0};
    char pos_buff[SIZE] = {0};
    
    char  ret = 0;

    unsigned int num = 0;
    unsigned int n_bits = 0;
    unsigned int pos = 0;


L1: // taking raw data from the user
    puts("Enter the Number:*** Within << 4294967295 >> This Range Only ***");
    fgets(r_data1, SIZE, stdin);
    fflush(stdin);
   
    puts("enter no of bits:");
    fgets(bit_data, SIZE, stdin);
    fflush(stdin);

    puts("enter position:");
    fgets(pos_data, SIZE, stdin);
    fflush(stdin);
    // condition for to check the fgets is read the data or not
    if ((('\0' == *r_data1) || ('\n' == *r_data1))
        && (('\0' == *bit_data) || ('\n' == *bit_data))
            && (('\0' == *pos_data) || ('\n' == *pos_data))) {
        puts(" **** fgets failed to read the data ****");
        puts(" *** enter the data ***");
        goto L1; 
        // if not read the data from user control goes to read data again
    }
    
    ret = validation(r_data1, buff1) || validation(bit_data, bit_buff)
            || validation(pos_data, pos_buff);

    if (ret == 1) { // condition to chech data is valid or not
        puts("**** INVALID DATA ****");
        puts("*** enter the CORRECT DATA again ***");
        goto L1;
        // if data is not valid control goes to read data again
    }

    if (('-' == buff1[0]) || ('-' == bit_buff[0]) 
            || ('-' == pos_buff[0])) {
        // condition to check given numbers positive or not
        puts("*** Negative Numbers Are Not Allowed ***");
        puts("*** enter the positive numbers ***");
        goto L1;
        //if number is negative control goes to read data again from the user
    }

    num = my_atoi(buff1);
    n_bits = my_atoi(bit_buff);
    pos = my_atoi(pos_buff);

    puts("Actual number is:");
    binary_print(num);
    printf("Number = %u\n", num);
       
    getbits(num, pos, n_bits);

    puts("Resultent number is:");
    binary_print(num);
    printf("Number = %u\n", num);
        
    return 0;
}