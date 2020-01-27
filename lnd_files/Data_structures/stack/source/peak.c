#include <header.h>

extern int top;

void peak(void) {

    if (SIZE == top) {
        puts("stack is at the top");
    } else {
        printf("present stack at position --> %d\n", top);
    }

}
