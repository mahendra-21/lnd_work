#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
    int fd = 0;
    int ret = 0;
    char *str = NULL;

    fd = open("created", O_CREAT | O_WRONLY);

    if (EOF == fd) {
        perror("open");
        return 0;
    }

    ret = write(fd, "hello, global", 13);

    if (EOF == ret) {
        puts("write is failed");
        return 0;
    }

    printf("write ret = %d\n", ret);
    
    ret = close(fd);

    if (EOF == ret) {
        puts("close is failed");
        return 0;
    }

    printf("fd = %d\n", fd);
    
    return 0;
}
