#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>

int var = 10;

int main(void)
{
    int fd;
    int ret;

    fd = open("/dev/myChar", O_RDWR);
    
    if (fd < 0)
        perror("Unable to open the device");
    else
        printf("File opened successfully %d\n", fd);
    
    pid_t pid = fork();

    if (pid > 0) {
        ret = ioctl(fd, getpid(), &var);
        printf("pid = %d    var = %d\n", getpid(), var);
        getchar();
    } else {
        ret = ioctl(fd, getpid(), &var);
        printf("pid = %d    var = %d\n", getpid(), var);
    }

    close(fd);
    return 0;
}


