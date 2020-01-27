#include "alloc.h"

char memory[MEM_SIZE]; /* Static array  to allocate memory for user */
uint32_t cur_mem = MEM_SIZE; /* Current size left in memory(static array) */
/* Array(64 - bytes) to maintain the meta_data of 1024 - bytes */
uint32_t m_data[MDATA] = {0}; 


/* Own memory allocation function */
void *
my_alloc(size_t size) {
    char *Addr = (char *)memory; /* Assigning base addr. for referencing */
    /* Calculating the bits to set in meta_data for user asked size */
    int n_bits = (!(size %4)) ? (size / 4) : (size / 4) + 1;
    int off_set; /* Addr to return for user ((# bit's  * 4) + base_addr) */
    int hit; /* To add for off_set when free size is not fit 
                for user asked size */
    int out_l; /* To rotate loops (for outer loop & inner loop) */
    int in_l;
    int next; /* To move next continueous bit's after 32 - bit's in meta_data */
    int help; 
    int free_bits; /* To know how much free size is left 
                      in the gaps after free the memory */

    /* If user size is more than current memory size, returning NULL */
    if (size > cur_mem) {
        printf("No Memory To Allocate\n");
        return NULL;
    }
   
    /* Setting bits in meta_data as per user required memory */
    for (out_l = 31, next = 0, off_set = 0; ((0 <= out_l) && 
                (MDATA > next)); --out_l) {
        /* If current out_l bit is set incrementing the off_set & continuing
           the loop.  If current out_l bit is not set checking the previous
           bit whether that bit is set or not. If previous bit is set 
           continuing the loop. If both the conditions false condition goes to
           else part */
        if ((m_data[next] >> out_l) & 1) {
            off_set++;
            if (0 == out_l) { 
                out_l = 32; 
                next++; 
            }
            continue;
        } else if ((m_data[next] >> (out_l + 1)) & 1) { 
            if (0 == out_l) {
                out_l = 32; 
                next++; 
            }
            continue;
        } else {
            if (!((m_data[next] >> out_l) & 1)) {
                /* If current bit position is not set calculating the free_bits
                   (which are unset in the meta_data */
                for (in_l = out_l, help = next, free_bits = 0, hit = 0; 
                        ((in_l >= 0) && (help < MDATA)); --in_l) {

                    if (!((m_data[help] >> in_l) & 1)) {
                        free_bits++;
                    } else {
                        free_bits -= 1;
                        hit++;
                        break;
                    }

                    if (0 == in_l) {
                        in_l = 32;
                        help++;
                    }
                }
                /* If free_bits in the meta_data are more than required n_bits
                   allocating the memory to the user (n_bits are setting in
                   the meta_data) or else incrementing the off_set & changing
                   the current bit positions for continuing the outer loop */
                if (free_bits >= n_bits) {
                    for (in_l = out_l; ((in_l >= 0) && (n_bits > 0));
                            --in_l, --n_bits) {
                        m_data[next] |= 1 << in_l;
                        cur_mem -= 4;

                        if (0 == in_l) {
                            in_l = 32;
                            next++;
                        }
                    }
                    break;
                } else {
                    out_l = in_l;
                    next = help;
                    off_set += free_bits + hit;
                    if (0 == out_l) {
                        out_l = 32;
                        next++;
                    }
                    continue;
                }
            }
        }
    }
    return (Addr + (off_set * 4));
}
