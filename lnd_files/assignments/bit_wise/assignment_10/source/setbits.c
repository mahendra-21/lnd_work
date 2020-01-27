/* function for to extract the bits in a actual number */

#include <header.h>

void setbits(unsigned int *result, unsigned int num,
                unsigned int n_bits, unsigned int pos) {

    puts("*************************************************");
    
    if (pos < n_bits) {

        puts("** scanning bits are not available **");
        puts("** no of bits should be (pos > n_bits) **");
    
        exit(0);
    }

    puts("*************************************************");

    int bits = (sizeof (int) * 8) - 1;

    unsigned int mask = 0;

    /********************************************************

            mask = ((1 << pos) - 1) << (pos - n_bits);

            *result = (num & mask) | *result;

     ********************************************************/       


    mask = num << (bits - pos);

    mask = mask >> (bits + 1 - n_bits);

    mask = mask << (pos + 1 - n_bits);

    *result |= mask;

}
