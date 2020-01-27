#include <stdio.h>

int main()
{
    char arr[4][3] = {{'M', 'b', 'c'}, {'A', 'e', 'f'}, 
                            {'g', 'h', 'i'}, {'j', 'k', 'l'}};

//    char (*ptr_arr)[3] = &arr; // pointer to an array

/* above line generates,  

  warning: initialization from incompatible pointer type [enabled by default]
        char (*ptr_arr)[3] = arr; 
        //to avoid this type cast it with void poinetr

****************    char (*ptr_arr)[3] = (void *) arr;     *****************

 */

/*    char (*ptr_arr)[3] = {{'M', 'b', 'c'}, {'A', 'e', 'f'}, 
                            {'g', 'h', 'i'}, {'j', 'k', 'l'}};
 *//*above line generates warning: braces around scalar initializer */

    char (*ptr_arr)[3] = (void *)arr;

    int start = 0;

    char *ptr = NULL;

    for (start = 0; start < 4; start++) {

        ptr = (char *)ptr_arr++; 

        printf("char = %c\n", *(ptr + 1));

    }
    
    return 0;
}
