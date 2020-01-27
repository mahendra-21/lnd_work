#include <header.h>

void display(int *stack) {

    int temp = SIZE - 1;

    if (EMPTY < temp) {

        while(EMPTY != temp) {
            printf("stack[%d] = %d\n", temp, stack[temp]);
            temp--;
        }

    } else {
        isempty();
    }

}
