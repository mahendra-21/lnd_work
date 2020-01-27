/*Given the bit position s in number snum and the bit position d
  in number dnum, swap bit values between s and d */

#include <header.h>

int main()
{
    char r_data1[SIZE] = {0};
    char r_data2[SIZE] = {0};
    
    char s_data[SIZE] = {0};
    char d_data[SIZE] = {0};

    char buff1[SIZE] = {0};
    char buff2[SIZE] = {0};

    char s_buff[SIZE] = {0};
    char d_buff[SIZE] = {0};
    
    char  ret = 0;

    unsigned int num1 = 0;
    unsigned int num2 = 0;

    unsigned int s_bit_pos = 0;
    unsigned int d_bit_pos = 0;
    
L1: // taking raw data from the user
    puts("Enter the Number:*** Within << 4294967295 >> This Range Only ***");
    fgets(r_data1, SIZE, stdin);
    fflush(stdin);

    puts("Enter the Number:*** Within << 4294967295 >> This Range Only ***");
    fgets(r_data2, SIZE, stdin);
    fflush(stdin);
    
    puts("enter source bit position:");
    fgets(s_data, SIZE, stdin);
    fflush(stdin);

    puts("enter destination bit position:");
    fgets(d_data, SIZE, stdin);
    fflush(stdin);
    // condition for to check the fgets is read the data or not
    if ((('\0' == *r_data1) || ('\n' == *r_data1))
        && (('\0' == *s_data) || ('\n' == *s_data))
            && (('\0' == *d_data) || ('\n' == *d_data))
                && (('\0' == *r_data2) || ('\n' == *r_data2))) {
        puts(" **** fgets failed to read the data ****");
        puts(" *** enter the data ***");
        goto L1; 
        // if not read the data from user control goes to read data again
    }
    
    ret = validation(r_data1, buff1) || validation(s_data, s_buff)
            || validation(d_data, d_buff) || validation(r_data2, buff2);

    if (ret == 1) { // condition to chech data is valid or not
        puts("**** INVALID DATA ****");
        puts("*** please enter the CORRECT DATA again ***");
        goto L1;
        // if data is not valid control goes to read data again
    }

    if (('-' == buff1[0]) || ('-' == s_buff[0]) 
            || ('-' == d_buff[0]) || ('-' == buff2[0])) {
        // condition to check given numbers positive or not
        puts("*** Negative Numbers Are Not Allowed ***");
        puts("*** please enter the positive numbers ***");
        goto L1;
        // if number is negative control goes to read data again from the user
    }

    num1 = my_atoi(buff1);
    num2 = my_atoi(buff2);

    s_bit_pos = my_atoi(s_buff);
    d_bit_pos = my_atoi(d_buff);

    puts("Before Swapping");
    binary_print(num1);
    printf("Number1 = %u\n", num1);
    
    binary_print(num2);
    printf("Number2 = %u\n", num2);
    
    bit_swap(&num1, &num2, s_bit_pos, d_bit_pos); // calling the function to 
                                          // swap the bit positions

    puts("After Swapping");
    binary_print(num1);
    printf("Number1 = %u\n", num1);
    
    binary_print(num2);
    printf("Number2 = %u\n", num2);
        
    return 0;
}
