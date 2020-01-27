#include <header.h>

int merge_sort(int arr[], int left, int right) {

    int mid  = 0;

    if (left < right) {
        mid = (right + left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

    return SUCCESS;
}
