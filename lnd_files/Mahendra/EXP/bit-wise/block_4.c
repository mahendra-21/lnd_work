#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE 1024

uint32_t block4[16] = {0};
char memory[SIZE];
static uint32_t cur_mem = SIZE;
int size_flag = 0;

void *my_alloc(size_t size);
int alloc_4(int size);
void binary(void);

int main(void)
{
    char *ptr1 = NULL;
    char *ptr2 = NULL;

    ptr1 = (char *)my_alloc(sizeof(int) * 1);
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

    if ((size >= 4) || (size < 4)) {
        ret = alloc_4(size);
        while (0 < ret) {
            size_flag = 1;
            ret = alloc_4(ret);
        }
    }

    return (addr + off_set);
}

int alloc_4(int size) {
    static int loop;
    static int next;
    int flag = 0;
    
    for (loop = 31, next = 0; ((loop >= 0) && (next < 16)); --loop) {
        if (0 == loop) {
            loop = 32;
            next++;
        }

        if ((block4[next] >> loop) & 1) {
            flag = 1;
            continue;
        } else if ((size_flag == 0) && (flag == 1)) {

        } else { 
            block4[next] |= 1 << loop;
            size -= 4;
            cur_mem -= 4;
            return size;
        }
    }

}    

void binary(void) {
    int loop;
    int next;

    for (loop = 31, next = 0; ((loop >= 0) && (next < 16)); --loop) {
        printf("%d", (block4[next] >> loop) & 1);
        if (loop % 8 == 0)
            printf(" ");
        
        if (loop == 0) {
            loop = 32;
            next++;
            if (next % 2 == 0)
                printf("\n");
        }
    }

    printf("\n");
}
