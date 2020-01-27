#include "../header.h"

int main(int argc, char *argv[])
{
    if (2 != argc) {
        fprintf(stderr, "Usage: %s <file> \n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fd;
    char *str = (char *)malloc(LEN);

    if (NULL == str) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    if (-1 == mkfifo(argv[1], 0664)) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    if (-1 == (fd = open(argv[1], O_RDONLY))) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    read(fd, str, LEN);
    fprintf(stdout, "string -> %s", str);
//        write(STDOUT_FILENO, str, sizeof(str));

    return 0;
}
