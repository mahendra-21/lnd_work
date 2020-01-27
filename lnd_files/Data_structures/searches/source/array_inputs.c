#include <header.h>

int array_inputs(int arr[], int num_ele) {
    
    if (FAILURE == num_ele) return FAILURE;

    int loop = 0;
    printf("Enter the elements in an array: ");

    for (loop = 0; loop < num_ele; loop++)
        arr[loop] = get_number();

    return SUCCESS;
}
