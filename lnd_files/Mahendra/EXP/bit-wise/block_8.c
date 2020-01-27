#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 1024

uint32_t block8[4] = {0};
char memory[SIZE];
static uint32_t cur_mem = SIZE;

void *my_alloc(size_t size);
int alloc_8(int size);
void binary(void);

int main(void)
{
    char *ptr1 = NULL;
    char *ptr2 = NULL;

    ptr1 = (char *)my_alloc(sizeof(int) * 3);
    printf("ptr -> %p\n", ptr1);

    binary();

    ptr2 = (char *)my_alloc(5);
    printf("ptr -> %p\n", ptr2);

    binary(); 
    printf("cur_mem -> %d\n", cur_mem);
    
    exit(EXIT_SUCCESS);
}

void *my_alloc(size_t size) {
    int loop;
    int off_set = 0;
    char *addr = (char *)memory;
    int ret;

    if (size > cur_mem) {
        printf("No Memory To Allocate\n");
        exit(EXIT_FAILURE);
    }

    printf("cur_mem -> %d\n", cur_mem);
    off_set = SIZE - cur_mem;

    if ((size >= 8) || (size < 8)) {
        ret = alloc_8(size);
        while (0 < ret)
            ret = alloc_8(ret);
    }

    return (addr + off_set);
}

int alloc_8(int size) {
    static int loop;
    static int next;
    
    for (loop = 31, next = 0; ((loop >= 0) && (next < 8)); --loop) {
        if (0 == loop) {
            loop = 32;
            next++;
        }

        if ((block8[next] >> loop) & 1) {
            continue;
        } else {
            block8[next] |= 1 << loop;
            size -= 8;
            cur_mem -= 8;
            return size;
        }
    }

}    

void binary(void) {
    int loop;
    int next;

    for (loop = 31, next = 0; ((loop >= 0) && (next < 4)); --loop) {
        printf("%d", (block8[next] >> loop) & 1);
        if (loop % 8 == 0)
            printf(" ");
        
        if (loop == 0) {
            loop = 32;
            next++;
            printf("\n");
        }
    }

    printf("\n");
}
