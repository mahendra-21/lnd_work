/* alloc.h */
#include <stdio.h>
#include <stdint.h>

/* Static array SIZE */
#define MEM_SIZE 1024

/* META_DATA Size (MDATA * 4) */
#define MDATA 16

/* Allocate SIZE bytes of memory */
void *my_alloc(size_t size);

/* Free a memory allocated by `my_alloc' */
void my_free(void *addr);

/* Printing Binary of META_DATA */
void binary(void);
