/* function for to copy n  bits in source num to a destination number */

#include <header.h>

void bitcopy(unsigned int s_num, unsigned int *d_num, unsigned int n_bits,
                unsigned int s_pos, unsigned int d_pos) {

    puts("*************************************************");
    
    if ((s_pos < n_bits) || (d_pos < n_bits)) {

        puts("** scanning bits are not available **");
        puts("** no of bits should be (pos > n_bits) **");
    
        exit(0);
    }

    int bits = (sizeof (int) * 8) - 1;

    unsigned int mask1 = 0;
    
    unsigned int mask2 = 0;
    
    mask1 = s_num << (bits - s_pos);
    mask1 = mask1 >> (bits + 1 - n_bits);
    mask1 = mask1 << (d_pos + 1 - n_bits);

    
    mask2 = *d_num << (bits - d_pos);
    mask2 = mask2 >> (bits + 1 - n_bits);
    mask2 = mask2 << (d_pos + 1 - n_bits);
    
    *d_num = *d_num ^ mask2;

    *d_num = *d_num | mask1;

}
