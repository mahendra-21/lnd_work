/* Partition function */
#include <header.h>
int partition(int arr[], int start, int end) {

    int pivot = arr[end];
    int help = (start - 1);
    int loop = 0;

    for (loop = start; loop < end; loop++) {

        if (arr[loop] <= pivot) {
            help++;
            swap_ele(&arr[help], &arr[loop]);
        }
        
    }

    swap_ele(&arr[help + 1], &arr[end]);
    return (help + 1);
}
