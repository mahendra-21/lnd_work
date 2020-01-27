#include <stdio.h>

#if 0
struct st {
    char a;
    int :0;
    char d;
    short :9;
    char b;       
}S;

int main(void)
{
    printf("size -> %d\n", sizeof(S));
    return 0;
}
#endif

#if 1
struct st {
    char a;
    int :0;
    char b;
    int :1;
}S;

int main(void) 
{ 
    printf("size -> %d\n", sizeof(S));
    return 0;
}
#endif
