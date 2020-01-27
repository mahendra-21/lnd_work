#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>

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
	
	printf("var = %lx\n", (unsigned long)&var);    
    ret = ioctl(fd, getpid(), &var);
	printf("%d\n", var);
    close(fd);

    return 0;
}


