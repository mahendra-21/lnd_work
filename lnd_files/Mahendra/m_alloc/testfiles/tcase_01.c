/**
 *  @file      tcase_01.c 
 *  @brief     Test case for the dyn_alloc functions. Allocating 256 time's
 *             1-byte to the user. After that allocating 1 more byte without 
 *             freeing.
 *  @author    Lakku Mahendra
 *  @date      16-Aug-2019
 *  @bug       No known bugs.
 *  @copyright No copyrights associated. Readers are free to use it every where,
 *             any where.
 */

#include <alloc.h>

/* Error handling macro */
#define error_handler(msg) do {\
                               printf("%s\n", msg);\
                               return 0;\
                           } while (0)

int main(void)
{
    char *ptr1 = NULL;
    char *ptr2 = NULL;
    int _itr = 1;

    while (257 != _itr) {
        ptr1 = (char *)dyn_alloc(sizeof(char) * 1);
        if (NULL == ptr1)
            error_handler("dyn_alloc failed");
        printf("%d. ptr1 addr -> %p\n", _itr++, ptr1);
    }

    #if DEF
    dump_info();
    #endif
    
    ptr2 = (char *)dyn_alloc(sizeof(char) * 1);
    if (NULL == ptr2)
        error_handler("dyn_alloc failed");
    printf("ptr2 addr -> %p\n", ptr2);

    return 0;
}
