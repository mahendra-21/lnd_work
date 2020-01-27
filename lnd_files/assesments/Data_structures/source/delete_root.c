#include "header.h"

DEL *delete_root(DEL *root)
{
    if (NULL == root)   return NULL;

    if ((NULL == root -> prev) && (NULL == root -> next)) {
        free(root);
        return NULL;
    } else {
        DEL *temp = root -> prev;
        DEL *temp1 = root -> next;

        if ((NULL == temp -> next)) {
            temp -> next = root -> next;
            free(root);
            return temp;
        } else if ((NULL == temp1 -> prev)) {
            temp1 -> prev = root -> prev;
            free(root);
            return temp1;
        } else {
            DEL *help = NULL;

            while ((NULL != temp -> next) && (NULL != temp -> prev)) {
                help = temp;
                temp = temp -> next;
            }

            help -> next = NULL;
        }

        temp -> prev = root -> prev;
        temp -> next = root -> next;
        free(root);
        return temp;
    }
}
