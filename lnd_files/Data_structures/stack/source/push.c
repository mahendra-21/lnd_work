#include <header.h>

extern int top;

int push(int *stack, int number) {

    if (SIZE == top) {
       isfull(); 
    }
    
    top++;
    stack[top] = number;

    return stack[top];
}
