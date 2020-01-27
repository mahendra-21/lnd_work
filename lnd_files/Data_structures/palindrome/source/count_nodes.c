#include <header.h>

int node_count(SL **hptr) {
    int count = 0;
    
    SL *temp = *hptr;

    while (temp != NULL) {
        count ++;
        temp = temp -> link;
    }

    return count;
}

