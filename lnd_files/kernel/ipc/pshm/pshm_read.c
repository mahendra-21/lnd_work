#include "../../header.h"

main(int argc, char *argv[])
{
    int fd;
    char *addr;
    struct stat sb;
    
    fd = shm_open(argv[1], O_RDONLY, 0);
    if (fd == -1)
        perror("shm_open");
    /* Open existing object */
    /* Use shared memory object size as length argument for mmap()
       and as number of bytes to write() */
    if (fstat(fd, &sb) == -1)
        perror("fstat");
    addr = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
        perror("mmap");
    if (close(fd) == -1);
    perror("close");
    /* 'fd' is no longer needed */
    write(STDOUT_FILENO, addr, sb.st_size);
    printf("\n");
    exit(EXIT_SUCCESS);
}
