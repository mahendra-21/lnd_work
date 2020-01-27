/**
 *  @file      tcase_02.c
 *  @brief     Test case for dyn_alloc functions. Invoking the dyn_alloc()
 *             function with 7-byes, 10-bytes. After that freeing the memory
 *             space allocated to the ptr2 (10-bytes). Again asking 9-bytes
 *             and freeing memory space allocated to the ptr1 (7-bytes).
 *             After again invoking with 23-bytes.
 *  @author    Lakku Mahendra
 *  @date      16-Aug-2019
 *  @bug       No known bugs 
 *  @copyright No copyrights associated. Readers are free to use it every where,
 *             any where.
 */

#include <alloc.h>

int main(void)
{
    char *ptr1 = NULL;
    char *ptr2 = NULL;
    char *ptr3 = NULL;
    char *ptr4 = NULL;

    /* Invoking dyn_alloc function with 7-bytes */
    ptr1 = (char *)dyn_alloc(sizeof(char) * 7);
    if (NULL == ptr1) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr1);
    #if DEF
    dump_info();
    #endif

    /* Invoking dyn_alloc function with 10-bytes */
    ptr2 = (char *)dyn_alloc(sizeof(char) * 10);
    if (NULL == ptr2) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr2);
    #if DEF
    dump_info();
    #endif

    /* Freeing the memory space allocated to the ptr2 */
    dyn_free(ptr2);
    #if DEF
    printf("After ptr2 free :\n");
    dump_info();
    #endif


    /* Invoking dyn_alloc function with 9-bytes */
    ptr3 = (char *)dyn_alloc(sizeof(char) * 9);
    if (NULL == ptr3) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr3);
    #if DEF
    dump_info();
    #endif

    /* Freeing the memory space allocated to the ptr1 */
    dyn_free(ptr1);
    #if DEF
    printf("After ptr1 free :\n");
    dump_info();
    #endif

    /* Invoking dyn_alloc function with 23-bytes */
    ptr4 = (char *)dyn_alloc(sizeof(char) * 23);
    if (NULL == ptr4) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr4);
    #if DEF
    dump_info();
    #endif

    return 0;
}
