#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>

int main(void)
{
    int fd;
    int ret;

    fd = open("/dev/myChar", O_RDWR);
    
    if (fd < 0)
        perror("Unable to open the device");
    else
        printf("File opened successfully %d\n", fd);
    
    ret = ioctl(fd, getpid(), 0);
    printf("pid = %d\n", getpid());
getchar();
    close(fd);
    return 0;
}


