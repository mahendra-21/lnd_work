/**
 *  @file      shift_bits.c  
 *  @brief     shifting the bits with their range.
 *  
 *  @author    Lakku Mahendra
 *  @date      18-Aug-2018 
 *  @bug       No Known bugs
 *
 *  @copyright No copyrights associated. Readers are free to use it every where,
 *             any where.
 */

#include <stdio.h>  
#include <stdint.h>

uint8_t block[2] = {0};

void dump_info(void);

int main(void)
{
    int i;
    int _n;
    unsigned int bit;

    block[0] = 0x8a;
    block[1] = 0xc0;
    
    printf("Before:\n");
    dump_info();

    for (i = 4, _n = 0; (i >= 0) && (_n < 2); --i) {
        
        if (0 == i) {
            if ((bit = ((block[_n + 1] >> 7) & 1)) == 1)
                block[_n] |= bit << i;
            else
                block[_n] |= (block[_n] & (bit << i));
        } else {
            if ((bit = ((block[_n] >> (i - 1)) & 1)) == 1)
                block[_n] |= bit << i;
            else
                block[_n] |= (block[_n] & (bit << i));
        }

        if (0 == i) {
            i = 8;
            _n++;
        }

    }
    
    printf("After:\n");
    dump_info();

    return 0;
}

void dump_info(void) {
    int i;
    int _n;

    for (i = 7, _n = 0; (i >= 0) && (_n < 2); --i) {
        printf("%d", (block[_n] >> i) & 1);
        if (i % 4 == 0)
            printf(" ");
        if (0 == i) {
            i = 8;
            _n++;
        }
    }

    printf("\n");
}
