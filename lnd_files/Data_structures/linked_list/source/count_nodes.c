#include <header.h>

int sll_node_count(SL **hptr) {
    int count = 0;
    
    SL *temp = *hptr;

    while (temp != NULL) {
        count ++;
        temp = temp -> link;
    }

    return count;
}

int dll_node_count(DL **hptr) {
    int count = 0;
    
    DL *temp = *hptr;

    while (temp != NULL) {
        count ++;
        temp = temp -> next;
    }

    return count;
} 
