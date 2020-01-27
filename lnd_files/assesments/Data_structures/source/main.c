#include "header.h"

int main(void)
{
    DEL *root = NULL;

    if (FLAG == (root = insert_node()))
        printf("node is not creating in the insert_node function\n");

    printf("BST :");
    print_bst(root);
    printf("\b\b\n");

    if (NULL == (root = delete_root(root))) {
        printf("BST having no nodes\n");
    } else {
        printf("BST :");
        print_bst(root);
        printf("\b\b\n");
    }

    return 0;
}
