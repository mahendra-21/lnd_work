#include "header.h"

DEL *create_node(void) {

    DEL *node = NULL;

    if (NULL == (node = (DEL *) malloc(sizeof(DEL)))) {
        perror("malloc");
        printf("DMA is failed\n");
        return NULL;
    } else {
        return node; 
    }

}
