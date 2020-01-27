#include "alloc.h"

extern uint32_t m_data[MDATA];

void binary(void) {
    int loop;
    int next;

    for (loop = 31, next = 0; ((0 <= loop) && (MDATA > next)); --loop) {
        printf("%d", ((m_data[next] >> loop) & 1));
        if (0 == (loop % 8))
            printf(" ");
        if (0 == loop) {
            loop = 32;
            next++;
            if (0 == (next % 2))
                printf("\n");
        }
    }
}
