#include <header.h>

int main(void)
{
    int ret = 0;
    int num_ele = 0;
    printf("Enter the number of elements in an array: ");
    num_ele = get_number();

    int arr[num_ele];
    int loop = 0;

    printf("Enter the array elements: ");
    for (loop = 0; loop < num_ele; loop++)
        arr[loop] = get_number();

    system("clear");
    printf("<------------------------------------------------>\n");
    printf("Before sorting ->: ");
    print_array(arr, num_ele);
    printf("\n<------------------------------------------------>\n");
    
    ret = sort_switch(arr, num_ele) ;

    if (FAILURE == ret) {
        printf("Error in Switch function\n");
        return 0;
    }
    
    printf("<------------------------------------------------>\n");
    printf("After sorting  ->: ");
    print_array(arr, num_ele);
    printf("\n<------------------------------------------------>\n");
    return 0;
}
