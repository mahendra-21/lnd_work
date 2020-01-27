#include <stdio.h>
#include <stdlib.h>

#define RG 4294967295UL

unsigned int myrand(unsigned int start_range, unsigned int end_range);

int main()
{
    unsigned int i_num = 0;

    unsigned int count = 0;

    unsigned int rand = 0;

    while (1) {
    
        rand = myrand(0, RG);
        
        if (rand >= 1 && rand <= 10) {
            count++;
            printf("%u ", rand);
        }
        
        if (count == 15) {
            exit (0);
        }
    
    }
    printf("\n");

//    for (; i_num <= count; i_num++) {
//        printf("%d ", arr[i_num]);
//    }

    return 0;
}

unsigned int myrand(unsigned int start_range, unsigned int end_range) {
    
    static unsigned int rand = 0;

    if (start_range == end_range) {

        return start_range;
    }
    
    rand += 0x3AD;
    rand %= end_range;

    while (rand < start_range) {
        rand = rand + end_range - start_range;
    }

    return rand;
}
