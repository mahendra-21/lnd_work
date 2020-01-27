#include "header.h"

void print_bst(DEL *root)
{
    if (NULL == root) return;
        
    print_bst(root -> prev);
    printf(" %d -", root -> data);
    print_bst(root -> next);
}
