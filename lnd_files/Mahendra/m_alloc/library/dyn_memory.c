/**
 *  @file      dyn_memory.c
 *  
 *  @brief     Allocating and freeing the memory.
 *  
 *  dyn_alloc() function allocates the memory for requested size bytes.
 *  For this based upon 4-bytes allignment in meta_data for each 4-bytes
 *  1-bit is setting and for differentiating each allocation leaving
 *  1-bit as zero.
 *  
 *  dyn_free() function frees the memory space pointed by the ptr, which
 *  must have been returned by a previous call to dyn_memory().
 *  For this in meta_data clearing the previously set bits by dyn_alloc()
 *  function allocated space.
 *  
 *  dump_info() function prints the meta_data for each dyn_alloc() & dyn_free()
 *  function calls.
 *  
 *  @author    Lakku Mahendra
 *  @date      15-Aug-2019 
 *  @bug       While freeing the mem space getting unexpected results.
 *  @copyright No copyrights associated. Readers are free to use it every where,
 *             any where.
 */

#include <alloc.h>

char memory[MEM_SIZE]; /* Static array to allocate memory for user */
uint32_t cur_mem = MEM_SIZE;
uint32_t m_data[MDATA];

/**
 *  @fn dyn_alloc - Allocates memory for requested size bytes
 *
 *  @param  size # of bytes to allocate to user
 *
 *  @return Returns the starting address from where it allocate.
 */
void *
dyn_alloc(size_t size) {
    char *addr = (char *)memory; 
    /* Calculating the bits to set in meta_data for user asked size */
    int free_bits; 
    int help; 
    int hit;
    int in_l;
    int out_l; 
    int off_set; /* Addr to return for user ((# bit's  * 4) + base_addr) */
    int next; 
    int n_bits = (!(size %4)) ? (size / 4) : (size / 4) + 1;

    /* If user size is more than current memory size, returning NULL */
    if (size > cur_mem) {
        printf("No Memory To Allocate\n");
        return NULL;
    }

    /* Setting bits in meta_data as per user required memory */
    for (out_l = 31, next = 0, off_set = 0; ((0 <= out_l) && 
                (MDATA > next)); --out_l) {
        /*
         * If current out_l bit is set incrementing the off_set & continuing
         * the loop.  If current out_l bit is not set checking the previous
         * bit whether that bit is set or not. If previous bit is set 
         * continuing the loop. If both the conditions false condition goes to
         * else part.
         */
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
                /* 
                 * If current bit position is not set calculating the free_bits
                 * (which are unset in the meta_data.
                 */
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
                /* 
                 * If free_bits in the meta_data are more than required n_bits,
                 * allocating memory to the user (n_bits - bits are setting in 
                 * the meta_data) or else incrementing the off_set & changing
                 * the current bit positions for continuing the outer loop.
                 */
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

//    dump_info(); /* To print the meta_data */
    /* 
     * Returning address by adding (off_set * 4) bytes to the base address of
     * static array.
     */
    return (addr + (off_set * 4)); 
}

/**
 * @fn dyn_free - Frees the allocated memory space 
 *
 * @param  ptr is a pointer pointed to the allocated memory space
 * 
 * @return void (Returns nothing).
 */
void 
dyn_free(void *ptr) {
    char *fre = ptr;
    int loop;
    int next;
    int n_bits = !(fre - memory) ? 0 : ((fre - memory) / 4) + 1;

    /* checking the how many bits has to free by rotating the loop
       till the address position get */
    for (loop = 31, next = 0; ((0 <= loop) 
                && (MDATA > next)); --loop) {
        /* checking how many bits has to move in m_data */
        if (0 != n_bits) {
            n_bits--;
            if (0 == loop) {
                loop = 32;
                next++;
            }
            continue;
        } else { // After going to the bit position clearing the bits
            if (!((m_data[next] >> loop) & 1))
                break;
            m_data[next] &= ~(1 << loop);
            cur_mem += 4;

            if (0 == loop) {
                loop = 32;
                next++;
            }
        }
    }
}

/**
 *  @fn : dump_info - prints the meta_data in binary format.
 *
 *  @param : void
 *
 *  @return : void
 */
void 
dump_info(void) {
    int loop; 
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
