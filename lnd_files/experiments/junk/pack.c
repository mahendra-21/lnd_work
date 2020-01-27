#include <stdio.h>

#pragma pack(4)
int main(void)
{
    struct st {
        char ch;
        int ch2;
    }t;

    printf("size = %d\n", sizeof(t));
    return  0;
}
