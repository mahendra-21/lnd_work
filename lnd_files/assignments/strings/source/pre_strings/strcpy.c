#include <stdio.h>
#include <string.h>

int main()
{
    char src[] = "reddy";

    char dest[] = "mahendra";

    char *ptr = strcpy(src, dest);

    printf("%s  %s\n", ptr, "mahi\0ndra");

    printf("%d\n", sizeof("mahi"));

    return 0;

}
