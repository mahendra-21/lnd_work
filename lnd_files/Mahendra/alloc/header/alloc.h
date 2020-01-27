#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MEM_SIZE 1024
#define MDATA 16

void *my_alloc(size_t size);
void my_free(void *addr);
void binary(void);
