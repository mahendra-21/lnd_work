#include <stdio.h>

#if flag
struct st {
    int var1:30;
    int :3;
    int var2:31;
    char var3:1;
}stt;

int main(void)
{
    printf("size -> %d\n", sizeof(stt));
    return 0;
}
#endif

#if flag1
struct st {
    int var1:30;
    int :0;
    int var2:31;
    char var3:1;
}stt;

int main(void)
{
    printf("size -> %d\n", sizeof(stt));
    return 0;
}
#endif
