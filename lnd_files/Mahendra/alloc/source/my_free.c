#include "alloc.h"

extern char memory[MEM_SIZE];
extern uint32_t m_data[MDATA];
extern uint32_t cur_mem;

void my_free(void *ptr) {
    char *fre = ptr;
    int loop;
    int next;
    int flag;
    int help;
    int n_bits = !(fre - memory) ? 0 : ((fre - memory) / 4) + 1;

    for (loop = 31, next = 0, flag = 0, help = 0; ((0 <= loop) 
                && (MDATA > next)); --loop) {

        if (0 != n_bits) {
            if ((m_data[next] >> loop) & 1) {
                if (1 < help) {
                    n_bits -= help - 1;
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
                flag = 1;
                continue;
            } else {
                help++;
                if (0 == loop) {
                    loop = 32;
                    next++;
                }
                continue;
            }
        } else if ((!(m_data[next] >> loop) & 1) && (1 == flag)) {
            printf("double free or corruption\n");
            break;
        } else {
            flag = 0;
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
