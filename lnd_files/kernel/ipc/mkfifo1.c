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
    

    if (-1 == (mkfifo(argv[1], 0664))) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_WRONLY);
    if (-1 == fd) {
        printf("hello\n");
        perror("open");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter the data: ");
    fgets(str, LEN, stdin);

    if (-1 == write(fd, str, strlen(str))) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    return 0;
}
