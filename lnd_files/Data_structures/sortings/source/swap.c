/* Swapping function */
#include <header.h>
void swap_ele(int *ptr, int *qtr) {

    int temp = *ptr;
    *ptr = *qtr;
    *qtr = temp;

}
