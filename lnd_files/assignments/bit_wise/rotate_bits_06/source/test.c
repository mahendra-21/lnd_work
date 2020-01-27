/*  Write the following functions
 *  
 *  a. unsigned int left_rotate_bits (unsigned int num);
 *               which will return the number, resulted by left rotating 
 *               the number num
 *  
 *  b. unsigned int right_rotate_bits (unsigned int num);
 *               which will return the number, resulted by right rotating 
 *               the number num
 *  
 *  c. unsigned int left_rotate_n_bits (unsigned int num, int n);
 *               which will return the number, resulted by left rotating 
 *               the number num by n bits
 *  
 *  d. unsigned int right_rotate_n_bits (unsigned int num, int n);
 *               which will return the number, resulted by right 
 *               rotating the number num by n bits
 */

#include <header.h>

int main()
{
    char r_data[SIZE] = {0};
    char buff[SIZE] = {0};

    char pos_data[SIZE] = {0};
    char pos_buff[SIZE] = {0};

    char  ret = 0;
    unsigned int pos = 0;
    unsigned int num = 0;

    
L1: // taking raw data from the user
    puts("Enter the Number:*** Within << 4294967295 >> This Range Only ***");
    fgets(r_data, SIZE, stdin);
    fflush(stdin);

    puts("enter the no of Bits:");
    fgets(pos_data, SIZE, stdin);
    fflush(stdin);

    // condition for to check the fgets is read the data or not
    if ((('\0' == *r_data) || ('\n' == *r_data))
        && (('\0' == *pos_data) || ('\n' == *pos_data))) {
        puts(" **** fgets failed to read the data ****");
        puts(" *** enter the data ***");
        goto L1; 
        // if not read the data from user control goes to read data again
    }
    
    ret = validation(r_data, buff) || validation(pos_data, pos_buff);

    if (ret == 1) { // condition to chech data is valid or not
        puts("**** INVALID DATA ****");
        puts("*** please enter the CORRECT DATA again ***");
        goto L1;
        // if data is not valid control goes to read data again
    }

    if (('-' == buff[0]) || ('-' == pos_buff[0])) {
        // condition to check given numbers positive or not
        puts("*** Negative Numbers Are Not Allowed ***");
        puts("*** please enter the positive numbers ***");
        goto L1;
        //if number is negative control goes to read data again from the user
    }

    num = my_atoi(buff);
    pos = my_atoi(pos_buff);
    
    switch_fun(num, pos);
        
    return 0;
}
