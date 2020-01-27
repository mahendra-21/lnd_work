/* Function for inverting the no of bits from the position */

#include <header.h>

void invert_bits(unsigned int *num, unsigned int n_bits, unsigned int pos) {

    unsigned int mask = 0;
    
    puts("***********************************************");

    if (pos < n_bits) {
        
        puts("** scanning bits are not available **");
        puts("** no of bits should be (pos > n_bits) **");
        
        exit(0);
    }

    puts("***********************************************");

    mask = (1 << n_bits) - 1;

    if (n_bits == 1) { 

        *num ^= (mask << pos);

    } else {

        *num ^= (mask << (pos - 1));

    }

}

