#include <stdio.h>

#pragma 1

int main(void)
{
    struct srt {
        struct ts {
            int va;
            char ch;
        }t;
        int var;
        char var2;
    };
    struct srt t1;
    struct ts t2;
    t2.va = 0;
    return 0;
}
