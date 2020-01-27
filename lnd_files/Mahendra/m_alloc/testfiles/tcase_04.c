/**
 *  @file      tcase_04.c 
 *  @brief     Allocating 10 bytes for_itr times. And freeing last allocated 
 *             memory space.
 *  @name      Global Edge Software LTD
 *  @author    Lakku Mahendra
 *  @date      23-Aug-2019
 *  @bug       While freeing last allocated memory space, in meta_data 
 *             dun_free() function clearing bit positions are not expected
 *             bit positions.
 *  @copyright No copyrights associated. Readers are free to use it every where,
 *             any where.
 */

#include <alloc.h>

int main(void)
{
    int *ptr = NULL;
    int _itr = 10;

    while (_itr--) {
        if (NULL == (ptr = (int *)dyn_alloc(sizeof(int) * 3))) {
            printf("dyn_alloc() function failed\n");
            return 0;
        }
    }

    #if DEF
    dump_info();
    #endif

    /* Freeing last allocated memory space to the ptr */
    dyn_free(ptr);
    #if DEF
    printf("After freeing 'ptr' in meta_data:\n");
    dump_info();
    #endif

    return 0;
}
