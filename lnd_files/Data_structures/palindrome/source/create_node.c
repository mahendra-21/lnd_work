#include <header.h>

SL *create_node(void) {
   
    SL *node = NULL;
    
    if (NULL == (node = (SL *) malloc(sizeof(SL)))) {
        perror("malloc");
        printf("DMA is failed\n");
        return NULL;
    } else {
        return node; 
    }

}

