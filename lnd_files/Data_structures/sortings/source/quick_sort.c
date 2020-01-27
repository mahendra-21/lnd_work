/* Funtion for quick-sort */
#include <header.h>
int quick_sort(int arr[], int left, int right) {
//    func = quick_sort;

    if (left < right) {
        int temp = partition(arr, left, right);
        quick_sort(arr, left, temp - 1);
        quick_sort(arr, temp + 1, right);
        //fun(arr, left, temp - 1);
        //fun(arr, temp + 1, right);
    }
    
    return SUCCESS;
}
