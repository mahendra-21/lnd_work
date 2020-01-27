/* Reverse a single linked list using recursion */
#include "header.h"

void *rec_rev(SL *head) {
    SL *temp_head = NULL;

    if ((NULL == head) || (NULL == head -> link))
        return head;

    temp_head = rec_rev(head -> link);

    head -> link -> link = head;
    head -> link = NULL;

    return temp_head;
}
