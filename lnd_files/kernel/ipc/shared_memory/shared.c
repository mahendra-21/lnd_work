#include "../../header.h"

int main(void)
{
    char* str;
    char* temp;
    void* ptr;
    int shm_fd;
    
    if (NULL == (str = (char *)malloc(LEN))) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    printf("Enter tha data: ");
    if (NULL == fgets(str, LEN, stdin)) {
        printf("fgets failed\n");
        exit(EXIT_FAILURE);
    }
    
    temp = str;
    while (*temp++)   
        if('\n' == *(temp - 1))   
            *(temp - 1) = *temp;
    
    shm_fd = shm_open("os", O_CREAT | O_RDWR, 0664);
    if (-1 == shm_fd) {
        printf("shm_open failed\n");
        exit(EXIT_FAILURE);
    }

    if (-1 == ftruncate(shm_fd, SIZE)) {
        printf("ftruncate failed\n");
        exit(EXIT_FAILURE);
    }

    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if ((void *) -1 == ptr) {
        printf("mmap failed\n");
        exit(EXIT_FAILURE);
    }

    sprintf(ptr, "%s", str);
    
    ptr += strlen(str);
    return 0;
}
