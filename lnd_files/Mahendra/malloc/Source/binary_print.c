/*
 * Printing the binary(digit's -> 0's or 1's) of meta_data. By using extern 
 * keyword we are accessing m_data array in current file which is in another
 * file.
 */
#include "alloc.h"

extern uint32_t m_data[MDATA];

void binary(void) {
    int loop; // Rotating the loop and changing the following following array's
    int next;
    
    for (loop = 31, next = 0; ((0 <= loop) && (MDATA > next)); --loop) {
        printf("%d", ((m_data[next] >> loop) & 1));
        
        if (0 == (loop % 8)) /* Providing spaces after 8 - digits */
            printf(" ");
   
        if (0 == loop) { // After printing 32 - bit's changing next 32 - bit's
            loop = 32;
            next++;
            if (0 == (next % 2)) /* Printing o/p at the next line after
                                    16 - bytes */
                printf("\n");
        }
    }
}
