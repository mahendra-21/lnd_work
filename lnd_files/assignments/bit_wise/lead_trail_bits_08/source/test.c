/*===>
 *      Write the following functions 
 *
 * a. int cnt_leading_set_bits (int num)
 *       returns the number of leading set bits
 *  
 * b. int cnt_leading_cleared_bits (int num)
 *       returns the number of leading cleared bits
 *  
 * c. int cnt_trailing_cleared_bits (int num)
 *       returns the number of trailing cleared bits
 *  
 * d. int cnt_trailing_set_bits (int num)
 *       returns the number of trailing set bits
 *
 */

#include <header.h>

int main()
{
    char r_data[SIZE] = {0};
    char buff[SIZE] = {0};
    
    unsigned char  ret = 0;
    
    unsigned int num = 0;

    
L1: // taking raw data from the user
    puts("Enter the Number:*** Within << 4294967295 >> This Range Only ***");
    fgets(r_data, SIZE, stdin);
    fflush(stdin);
    
    // condition for to check the fgets is read the data or not
    if (('\0' == *r_data) || ('\n' == *r_data)) {
        puts(" **** fgets failed to read the data ****");
        puts(" *** enter the data ***");
        goto L1; 
        // if not read the data from user control goes to read data again
    }
    
    ret = validation(r_data, buff);

    if (ret == 1) { // condition to chech data is valid or not
        puts("**** INVALID DATA ****");
        puts("*** please enter the CORRECT DATA again ***");
        goto L1;
        // if data is not valid control goes to read data again
    }

    if ('-' == buff[0]){
        // condition to check given numbers positive or not
        puts("*** Negative Numbers Are Not Allowed ***");
        puts("*** please enter the positive numbers ***");
        goto L1;
        // if number is negative control goes to read data again from the user
    }

    num = my_atoi(buff);

    switch_fun(num);
        
    return 0;
}
