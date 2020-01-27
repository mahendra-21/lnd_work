#include "../../header.h"

static void
usageError(const char *progName)
{
    fprintf(stderr, "Usage: %s [-cx] name size [octal-perms]\n", progName);
    fprintf(stderr, "  -c     Create shared memory (O_CREAT)\n");
    fprintf(stderr, "  -x     Create exclusively (O_EXCL)\n");
    exit(EXIT_FAILURE);
}

int
main(int argc, char *argv[])
{
    int flags, opt, fd;
    mode_t perms;
    size_t size;
    void *addr;
    flags = O_RDWR;

    while ((opt = getopt(argc, argv, "cx")) != -1) {
        switch (opt) {
            case 'c':
                flags |= O_CREAT;
                break;
            case 'x':
                flags |= O_EXCL;
                break;
            default:
                usageError(argv[0]);
        }
    }

    if (optind + 1 >= argc)
        usageError(argv[0]);
    size = atoi(argv[3]);

    /* Create shared memory object and set its size */
    fd = shm_open(argv[optind], flags, 0664);
    if (fd == -1)
        perror("shm_open");
    if (ftruncate(fd, size) == -1)
        perror("ftruncate");

    /* Map shared memory object */
    addr = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (addr == MAP_FAILED)
        perror("mmap");
    exit(EXIT_SUCCESS);
}
