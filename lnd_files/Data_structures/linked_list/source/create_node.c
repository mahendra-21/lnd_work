#include <header.h>

SL *sll_create_node(void) {
   
    SL *node = NULL;
    
    if (NULL == (node = (SL *) malloc(sizeof(SL)))) {
        perror("malloc");
        printf("DMA is failed\n");
        return NULL;
    } else {
        return node; 
    }

}

DL *dll_create_node(void) {
   
    DL *node = NULL;
    
    if (NULL == (node = (DL *) malloc(sizeof(DL)))) {
        perror("malloc");
        printf("DMA is failed\n");
        return NULL;
    } else {
        return node; 
    }

}
