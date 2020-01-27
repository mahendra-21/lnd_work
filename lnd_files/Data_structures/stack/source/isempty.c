#include <header.h>

extern int top;

void isempty(void) {

    if (EMPTY == top) {
        puts("Stack is in underflow");
    } else {
        printf("Stack is at position --> %d\n", top);
    }

}
