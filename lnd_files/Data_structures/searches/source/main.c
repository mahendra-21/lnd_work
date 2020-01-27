#include <header.h>

int main(void)
{
    int ret = 0;
    int num_ele = 0;
    int arr[num_ele];
    system("clear");

    while (1) {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("Enter the Size of an array: ");
        num_ele = get_number();
        
        arr[num_ele];

        ret = array_inputs(arr, num_ele);
        
        if (FAILURE == ret) {
            printf("Taking inputs from the user was failed\n");
            return FAILURE;
        }

        ret = switch_case(arr, num_ele);

        if (FAILURE == ret) {
            printf("In switch-case getting an error\n");
            return FAILURE;
        }

        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        ret = print_array(arr, num_ele);
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

        if (FAILURE == ret) {
            printf("Printing an array function getting an error\n");
            return FAILURE;
        }
        
        printf("Enter 1 to clear the screen: ");
        if (SUCCESS == get_number())    system("clear");
    }

    return exit;
}

