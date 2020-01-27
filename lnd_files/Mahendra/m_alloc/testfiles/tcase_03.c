/**
 *  @file      tcase_03.c
 *  @brief     Test case for dyn_memory functions.
               Invoking dyn_alloc() function with 0-bytes, -1, more than 1024 bytes.
 *  @name      Global Edge Software LTD
 *  @author    Lakku Mahendra
 *  @date      
 *  @bug       No Known bugs
 *  @copyright No copyrights associated. Readers are free to use it every where,
 *             any where.
 */

#include <alloc.h>

int main(void)
{
    int *ptr = NULL;
    if (NULL == (ptr = (int *)dyn_alloc(0))) {
        printf("dyn_alloc failed - asked for 0 bytes\n");
        return 0;
    }
    printf("ptr Addr. -> %p\n", ptr);

    if (NULL == (ptr = (int *)dyn_alloc(-1))) {
        printf("dyn_alloc failed - asked for -1 bytes\n");
    }

    if (NULL == (ptr = (int *)dyn_alloc(sizeof(char) * 1025))) {
        printf("dyn_alloc failed - asked for 1025 bytes\n");
    }
    return 0;
}    
