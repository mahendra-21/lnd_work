#include <stdio.h>
#include <string.h>

int main(void)
{
    char *ptr;

    ptr = (char *) memchr("1", 49, 5);
    printf("memchr -> %s\n", ptr);

    return 0;
}
