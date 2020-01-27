#include <header.h>

extern int top;

void isfull(void) {

    if (SIZE == top) {
        puts("Stack is overflow");
    } else  {
        printf("stack is at position --> %d\n", top);
    }

}
