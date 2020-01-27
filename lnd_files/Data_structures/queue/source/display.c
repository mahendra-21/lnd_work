#include <header.h>

void display(int *queue) {
    int loop = 0;

    for (loop = 0; loop < SIZE; loop++) {
        printf("queue[%d] = %d\n", loop, queue[loop]);
    }

}
