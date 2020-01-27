#include "../../header.h"

int main(void)
{
    int shm_fd;
    void* ptr;
    int fd;
    char *str;

    shm_fd = shm_open("os", O_RDONLY, 0666);
    if (-1 == shm_fd) {
        printf("shm_open failed\n");
        exit(EXIT_FAILURE);
    }

    ptr = mmap(NULL, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0);
    if ((void *) -1 == ptr) {
        printf("mmap failed\n");
        exit(EXIT_FAILURE);
    }
        
    str = (char *)malloc(LEN);
    if (NULL == str) {
        printf("malloc failed\n");
        exit(EXIT_FAILURE);
    }

    if (-1 == read(shm_fd, str, LEN)) {
        printf("read failed\n");
        exit(EXIT_FAILURE);
    }

    printf("str -> %s\n", str);
/*    fd = open("file", O_CREAT | O_RDWR, 0664);

    write(fd, str, strlen(str));
    
    if (-1 == shm_unlink("os")) {
        printf("shm_unlink failed\n");
        exit(EXIT_FAILURE);
    }
*/    return 0;
}

