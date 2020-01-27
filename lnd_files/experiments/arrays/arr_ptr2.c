#include <stdio.h>

int main()
{
    char arr[4][3] = {{'M', 'b', 'c'}, {'A', 'e', 'f'}, 
                            {'g', 'h', 'i'}, {'j', 'k', 'l'}};

//    char (*ptr_arr)[3] = &arr;  //here it give sthe warning
    char (*ptr_arr)[3] = (void *)arr;

    int start = 0;

    char *ptr = NULL;

    for (start = 0; start < 3; start++) {

        ptr = ptr_arr[1];

        printf("char = %c\n", *(ptr + start));

        ptr = NULL;

    }
    
   
    return 0;
}
