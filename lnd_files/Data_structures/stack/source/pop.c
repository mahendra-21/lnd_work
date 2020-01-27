#include <header.h>

extern int top;

int pop(int *stack) {
    
    int val = 0;

    if (EMPTY == top) {
        return 0;
    } 

    val = stack[top];
    stack[top] = 0;
    top--;

    return val;
}
