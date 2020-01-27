#include <stdio.h>

int evar = 20;
static int gsvar;

void func(void);

int main(void)
{
    int help = 10;
    static int lvar = 10;

    func();

    return 0;
}
