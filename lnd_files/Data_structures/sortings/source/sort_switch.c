#include <header.h>

int sort_switch(int arr[], int num_ele) {

    int ret = 0;
    int option = 0;
    
    while (1) {
        printf("Sorting Techniques:\n"
                "    1. Selection sort\n"
                "    2. Bubble sort\n"
                "    3. Insertion sort\n"
                "    4. Quick sort\n"
                "    5. Merge sort\n"
                "    0. Exit\n"
                "Enter the option: ");
        option = get_number();

        switch (option) {
            case    1:
                break;
            case    2:
                break;
            case    3:
                break;           
            case    4: 
                ret = quick_sort(arr, 0, num_ele - 1);

                if (SUCCESS == ret)
                    return SUCCESS;
                else {
                    printf("Quick sort is failed\n");
                    return FAILURE;
                }

                break;
            case    5:
                ret = merge_sort(arr, 0, num_ele - 1);

                if (SUCCESS == ret)
                    return SUCCESS;
                else {
                    printf("Merge sort is failed\n");
                    return FAILURE;
                }
                break;
            case    0: 
                exit(0);
                break;
            default  :
                printf("---> Incorrect Option. Enter again\n");
                break;
        }

    }
    
    return SUCCESS;
}
