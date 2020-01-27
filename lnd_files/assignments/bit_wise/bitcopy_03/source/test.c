/* Write a function   bit_copy (int snum, int dnum, int n, int s, int d) 
 * which copies n bits (right adjusted) from bit position s in snum to 
 * bit position d in dnum.
 */

#include <header.h>

int main()
{
    char r_data1[SIZE] = {0};
    char r_data2[SIZE] = {0};
    char bit_data[SIZE] = {0};
    char spos_data[SIZE] = {0};
    char dpos_data[SIZE] = {0};

    char buff1[SIZE] = {0};
    char buff2[SIZE] = {0};
    char bit_buff[SIZE] = {0};
    char spos_buff[SIZE] = {0};
    char dpos_buff[SIZE] = {0};
    
    char  ret = 0;

    unsigned int snum = 0;
    unsigned int dnum = 0;
    unsigned int n_bits = 0;
    unsigned int spos = 0;
    unsigned int dpos = 0;

L1: // taking raw data from the user
    puts("Enter the Source Number:*** Within << 4294967295 >> This Range Only ***");
    fgets(r_data1, SIZE, stdin);
    fflush(stdin);

    puts("Enter the Destination Number:*** Within << 4294967295 >> "
            "This Range Only ***");
    fgets(r_data2, SIZE, stdin);
    fflush(stdin);
    
    puts("enter no of bits:");
    fgets(bit_data, SIZE, stdin);
    fflush(stdin);

    puts("enter position:");
    fgets(spos_data, SIZE, stdin);
    fflush(stdin);
    
    puts("enter position:");
    fgets(dpos_data, SIZE, stdin);
    fflush(stdin);
    // condition for to check the fgets is read the data or not
    if ((('\0' == *r_data1) || ('\n' == *r_data1))
        && (('\0' == *bit_data) || ('\n' == *bit_data))
            && (('\0' == *spos_data) || ('\n' == *spos_data))
                && (('\0' == *dpos_data) || ('\n' == *dpos_data))
                     && (('\0' == *r_data2) || ('\n' == *r_data2))) {
        puts(" **** fgets failed to read the data ****");
        puts(" *** enter the data ***");
        goto L1; 
        // if not read the data from user control goes to read data again
    }
    
    ret = validation(r_data1, buff1) || validation(bit_data, bit_buff)
            || validation(spos_data, spos_buff) || validation(r_data2, buff2)
                                    || validation(dpos_data, dpos_buff);

    if (ret == 1) { // condition to chech data is valid or not
        puts("**** INVALID DATA ****");
        puts("*** enter the CORRECT DATA again ***");
        goto L1;
        // if data is not valid control goes to read data again
    }

    if (('-' == buff1[0]) || ('-' == bit_buff[0]) 
            || ('-' == spos_buff[0]) || ('-' == buff2[0])
                            || ('-' == dpos_buff[0])) {
        // condition to check given numbers positive or not
        puts("*** Negative Numbers Are Not Allowed ***");
        puts("*** enter the positive numbers ***");
        goto L1;
        // if number is negative control goes to read data again from the user
    }

    snum = my_atoi(buff1);
    dnum = my_atoi(buff2); 
    n_bits = my_atoi(bit_buff);
    spos = my_atoi(spos_buff);
    dpos = my_atoi(dpos_buff);

    puts("First number:");
    binary_print(snum);
    printf("Number = %u\n", snum);
    
    puts("Second number Before:");
    binary_print(dnum);
    printf("Number = %u\n", dnum);
    
    bitcopy(snum, &dnum, n_bits, spos, dpos); 

    puts("Second number After:");
    binary_print(dnum);
    printf("Number = %u\n", dnum);
        
    return 0;
}
