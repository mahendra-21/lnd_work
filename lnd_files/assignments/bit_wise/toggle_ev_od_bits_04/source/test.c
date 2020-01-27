/* Write the following functions which will toggle even bits 
   and odd bits respectively in a give number.

   a. Toggle even bit: int even_bit_toggle (int num);
   b. Toggle odd bit: int odd_bit_toggle (int num);
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

    puts("enter the option:<< 1. EVEN   2. ODD >>:");
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
    
    puts("Before Toggle");
    binary_print(num);
    printf("Number = %u\n", num);
    
    if (option == 1) {
        num = even_b_toggle(num);
    } else if (option == 2) {
        num = odd_b_toggle(num);
    } else {
        puts("*** Invalid Option ***");
        return 0;
    }
            
    puts("After Toggle");
    binary_print(num);
    printf("Number = %u\n", num);
        
    return 0;
}
