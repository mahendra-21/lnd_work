#include "alloc.h"

int main(void)
{
    char *ptr = NULL;
    int var = 10;

    while (--var) {
        ptr = my_alloc(sizeof(char) * 1);
        if (NULL == ptr) {
            printf("my_alloc failed\n");
            return 0;
        }
        printf("ptr - addr --> %p\n", ptr);
        binary();
    }
    return 0;
}
