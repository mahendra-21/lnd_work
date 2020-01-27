#include "alloc.h"

/* Accessing the global variables which are in another file */
extern char memory[MEM_SIZE];
extern uint32_t m_data[MDATA];
extern uint32_t cur_mem;

void 
my_free(void *ptr) {
    char *fre = ptr;
    int loop;
    int next;
    int help;
    int n_bits = !(fre - memory) ? 0 : ((fre - memory) / 4) + 1;

    /* checking the how many bits has to free by rotating the loop
       till the address position get */
    for (loop = 31, next = 0, help = 0; ((0 <= loop) 
                && (MDATA > next)); --loop) {
        /* checking how many bits has to move in m_data */
        if (0 != n_bits) {
            if ((m_data[next] >> loop) & 1) {
                if (1 < help) {
                    n_bits -= help;
                    if (0 == loop) {
                        loop = 32;
                        next++;
                    }
                    continue;
                }
                if (0 == loop) {
                    loop = 32;
                    next++;
                }
                n_bits--;
                continue;
            } else {
                help++;
                if (0 == loop) {
                    loop = 32;
                    next++;
                }
                continue;
            }
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
