#include <stdio.h>  
#include <stdint.h>

#define MEM_SIZE 1024

char memory[MEM_SIZE];
static uint32_t curr_mem = MEM_SIZE;
uint32_t block[16] = {0};

void *my_alloc(size_t size);
void my_free(void *ptr);
void binary(void);

int main(void)
{
    char *ptr1 = NULL;
    char *ptr2 = NULL;
    char *ptr3 = NULL;
    char *ptr4 = NULL;
    char *ptr5 = NULL;

    ptr1 = (char *)my_alloc(sizeof(char) * 7);
    if (NULL == ptr1) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr1);
    binary();
    
    ptr2 = (char *)my_alloc(sizeof(char) * 10);
    if (NULL == ptr2) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr2);
    binary();

    my_free(ptr1);
    printf("After free :\n");
    binary();
    
    ptr3 = (char *)my_alloc(sizeof(char) * 9);
    if (NULL == ptr3) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr3);
    binary();
    
    ptr4 = (char *)my_alloc(sizeof(char) * 23);
    if (NULL == ptr4) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr4);
    binary();
    
    my_free(ptr2);
    printf("After free :\n");
    binary();

/*
    my_free(ptr2);
    printf("After free :\n");
    binary();
    
    ptr5 = (char *)my_alloc(sizeof(char) * 12);
    if (NULL == ptr5) {
        printf("Malloc failed\n");
        return 0;
    }
    printf("addr -> %p\n", ptr5);
    binary();
  */  
    return 0;
}

void *my_alloc(size_t size) {
    int Oloop;
    int Iloop;
    int next;
    int flag;
    int n_size;
    int temp;
    int bit_count = 0;
    int count = 0;
    int help;
    char *addr = memory;

    if (size > curr_mem)    return NULL;

    n_size = (!(size % 4)) ? (size / 4) : (size / 4) + 1;

    for (Oloop = 31, next = 0; ((Oloop >= 0) && (next < 16)); --Oloop) {
        
        if ((block[next] >> Oloop) & 1) {
            count++;
            
            if (Oloop == 0) {
                Oloop = 32;
                next++;
            }
            
            continue;
        } else if ((block[next] >> (Oloop + 1)) & 1) {

            if (Oloop == 0) {
                Oloop = 32;
                next++;
            }
            continue;

        } else {
            flag = block[next] >> Oloop & 1;
            if (0 == flag) {
                temp = next;
                help = 0;
                for (Iloop = Oloop; ((Iloop >= 0) && (temp < 16)); --Iloop) {

                    if (!((block[temp] >> Iloop) & 1)) {
                        bit_count++;
                    } else {
                        help++;
                        bit_count -= 1;
                        break;
                    }
                    
                    if (Iloop == 0) {
                        Iloop = 32;
                        temp ++;
                    }
                }
            
                if (bit_count >= n_size) {
                    for (Iloop = Oloop; ((Iloop >= 0) && (n_size > 0)); 
                            --Iloop, --n_size) {
                        
                        block[next] |= 1 << Iloop;
                        curr_mem -= 4;
                        
                        if (Iloop == 0) {
                            Iloop = 32;
                            next++;
                        }
                    }
                    break;
                } else {
                    Oloop = Iloop;
                    next = temp;
                    count += help;
                    bit_count = 0;
                    continue; 
                }
                
            }
        }
        
    }

    return (addr + (count * 4));
}
    
void my_free(void *ptr) {
    char *fre = ptr;
    int n_bits;
    int loop;
    int next;
    int flag = 0;
    int count;

//    n_bits = ((fre - memory) / 4 ) + 1;
    n_bits = (0 == (fre - memory)) ? 0 : (((fre - memory) / 4) + 1);

    for (loop = 31, next = 0, count = 0; ((loop >= 0) && 
                (next < 16)); --loop) {

        if (n_bits != 0) {
            
            if ((block[next] >> loop) & 1) {
                if (1 < count) {
                    n_bits -= count - 1;
                    if (loop == 0) {
                        loop = 32;
                        next++;
                    }
                    continue;
                }
                if (loop == 0) {
                    loop = 32;
                    next++;
                }
                n_bits--;
                continue;
            } else {
                count++;
                if (loop == 0) {
                    loop = 32;
                    next++;
                }
                continue;
            }

        } else if ((!(block[next] >> loop) & 1) && (flag == 1)) {
            printf("double free or corruption\n");
            break;
        } else {
            flag = 0;
            if (!((block[next] >> loop) & 1))
                break;
            block[next] &= ~(1 << loop);
            curr_mem += 4;
            
            if (loop == 0) {
                loop = 32;
                next++;
            }
        }
    }
}

#if 0
void *my_alloc(size_t size) {
    static int loop;
    static int next;
    int size_count = 0;
    int off_set;
    char *addr = (char *)memory;
    int s_size = size;

    if (size > curr_mem)    return NULL;

    off_set = MEM_SIZE - curr_mem;

    if ((size >= 4) || (size < 4)) {
        for (loop = 31, next = 0, size_count = 0; 
                ((loop >= 0) && (next < 2)); --loop) {

            if (0 >= s_size)    break;

            if (16 == size_count) {
                size_count = 0;
                loop = 32;
                next++;
                continue;
            }

            if ((block[next] >> loop) & 1) {
                size_count++;
                continue;
            } else {
                block[next] |= 1 << loop;
                s_size -= 4;
                size_count++;
                curr_mem -= 4;
            }
        }
    }

    return (addr + off_set);
}
#endif

void binary(void) {
    int loop;
    int next;

    for (loop = 31, next = 0; ((loop >= 0) && (next < 16)); --loop) {
        printf("%d", ((block[next] >> loop) & 1));
        
        if (loop % 8 == 0)
            printf(" ");

        if (loop == 0) {
            loop = 32;
            next++;
            if (next % 2 == 0)
                printf("\n");
        }

    }
}
