#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 1024

uint32_t block32 = 0;
char memory[SIZE];
static uint32_t cur_mem = SIZE;

void *my_alloc(size_t size);
void binary(void);

int main(void)
{
    char *ptr1 = NULL;
    char *ptr2 = NULL;

    ptr1 = (char *)my_alloc(992);
    printf("ptr -> %p\n", ptr1);

    binary();

    ptr2 = (char *)my_alloc(32);
    printf("ptr -> %p\n", ptr2);

    binary();
    exit(EXIT_SUCCESS);
}

void *my_alloc(size_t size) {
    int loop;
    int off_set = 0;
    char *addr = (char *)memory;
    int s_size = size;

    if (size > cur_mem) {
        printf("No Memory To Allocate\n");
        exit(EXIT_FAILURE);
    }

    printf("cur_mem -> %d\n", cur_mem);
    off_set = SIZE - cur_mem;

    if (size >= 32) {
        for (loop = 31; loop >= 0; --loop) {
            if (0 >= s_size)  
                break;

            if ((block32 >> loop) & 1) {
                cur_mem -= 32;
            } else {
                block32 |= 1 << loop;
                s_size -= 32;
                cur_mem -= 32;
            }
        }
    }

    return (addr + off_set);
}

void binary(void) {
    int loop;
    for (loop = 31; loop >= 0; --loop) {
        printf("%d", (block32 >> loop) & 1);
        if (loop % 8 == 0)
            printf(" ");
    }
    printf("\n");
}
