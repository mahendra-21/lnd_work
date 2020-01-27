#include <header.h>

extern int *start;
extern int *last;
extern int index;

int enqueue(int *queue, int number) {
    
    if ((NULL == start) && (NULL == last)) {
        start = last = queue;
        *start = *last = number;
        index++;
    } else {
        *(++last) = number;
        index++;
    }

    return *last;
}
