#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define SIZE    128
#define SUCCESS 1
#define FAILURE 0
#define func    int (*fun)(int arr[], int var1, int var2)

int get_number (void);
int validation(const char *str, char *buff);
int my_atoi(const char *str);

/* Quick Sort */
int sort_switch(int arr[], int num_ele);
int quick_sort(int arr[], int left, int right);
int partition(int arr[], int start, int end);
void swap_ele(int *ptr, int *qtr);


/* Merge Sort */
int merge_sort(int arr[], int left, int right);
int merge(int arr[], int left, int middle, int right);

void print_array(int *arr, int num_ele);
