#include <header.h>

int merge(int arr[], int left, int middle, int right) {

    int help1 = left;
    int help2 = middle + 1;
    int temp_arr[right - left + 1];
    int temp;
    int loop;

    for (loop = left, temp = 0; loop <= right; loop++) {
        if (help1 > middle)
            temp_arr[temp++] = arr[help2++];
        else if (help2 > right) {
            temp_arr[temp++] = arr[help1++];
        else if (arr[help1] < arr[help2])
            temp_arr[temp++] = arr[help1++];
        else
            temp_arr[temp++] = arr[help2++];
    }

    for (loop = 0; loop < temp; loop++)
        arr[left++] = temp_arr[loop];

    return SUCCESS;
}
