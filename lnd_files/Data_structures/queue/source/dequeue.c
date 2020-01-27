#include <header.h>

extern int *start;
extern int *last;
extern int index;

int dequeue(int *queue) {
    int temp = 0;
    int help = 0;

    if (EMPTY == index) {
        return 0;
    }

    if (0 == index) {
        index = -1;
        temp = *start;
        start = last = NULL;
        queue[0] = 0;
    } else {
        --index;
        temp = *start;

        for (help = 0; help < index; help++) {
            queue[help] = *(start + 1 + help);
        }
        queue[help] = 0;

        last = last -1;
    }

    return temp;
}
