#include <stdio.h>
int main()
{
        char *arr_str[4]={"global", "edge", "software",                                                 "limited"};
            printf("arr_str[1] = %s\n", *(arr_str + 1));
//                printf("arr_str = %s\n", **arr_str);
                    printf("arr_str + 1 = %s\n", arr_str + 1);
                        return 0;
}

