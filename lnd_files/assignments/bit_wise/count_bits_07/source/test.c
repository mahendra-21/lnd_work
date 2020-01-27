/* Write the following functions which will count the 
   number of bits set and number of bits cleared
   in the given number num respectively
   
   a. count_bit_set (int num);
   b. count_bit_clear (int num);
 */
#include <header.h>

int main()
{
    char r_data[SIZE] = {0};
    char buff[SIZE] = {0};

    char op_data[5] = {0};
    char op_buff[5] = {0};

    char  ret = 0;
    unsigned int option = 0;
    unsigned int num = 0;

    
L1: // taking raw data from the user
    puts("Enter the Number:*** Within << 4294967295 >> This Range Only ***");
    fgets(r_data, SIZE, stdin);
    fflush(stdin);

    puts("enter the option:<< 1. SET_BITS    2. CLEAR_BITS >>:");
    fgets(op_data, SIZE, stdin);
    fflush(stdin);

    // condition for to check the fgets is read the data or not
    if ((('\0' == *r_data) || ('\n' == *r_data))
        && (('\0' == *op_data) || ('\n' == *op_data))) {
        puts(" **** fgets failed to read the data ****");
        puts(" *** enter the data ***");
        goto L1; 
        // if not read the data from user control goes to read data again
    }
    
    ret = validation(r_data, buff) || validation(op_data, op_buff);

    if (ret == 1) { // condition to chech data is valid or not
        puts("**** INVALID DATA ****");
        puts("*** please enter the CORRECT DATA again ***");
        goto L1;
        // if data is not valid control goes to read data again
    }

    if (('-' == buff[0]) || ('-' == op_buff[0])) {
        // condition to check given numbers positive or not
        puts("*** Negative Numbers Are Not Allowed ***");
        puts("*** please enter the positive numbers ***");
        goto L1;
        // if number is negative control goes to read data again from the user
    }

    num = my_atoi(buff);
    option = my_atoi(op_buff);
    
    puts("Binary Reprasentation is:");
    binary_print(num);
    printf("Number = %u\n", num);
    
    if (option == 1) {
        num = setbit_count(num);
    } else if (option == 2) {
        num = clearbit_count(num);
    } else {
        puts("*** Invalid Option ***");
        return 0;
    }
            
    puts("Count of the Bits is:");
    printf("Number = %u\n", num);
        
    return 0;
}
