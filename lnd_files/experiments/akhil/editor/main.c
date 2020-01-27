#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LIMIT    2

int main(int argc, char **argv)
{
    FILE *fp;

    if(LIMIT != 2) {
        puts("USAGE:./exe  <filename>");
        exit(0);
    }

    fp = fopen(argv[1], "r+");

    if (NULL == fp) {
        fp = fopen(argv[1], "w+");
    }


