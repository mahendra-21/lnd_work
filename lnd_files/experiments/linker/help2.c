#include <stdio.h>

extern int evar;

void func(void) {
    
    static int lfvar = 30;

    printf("evar in func = %d\n", evar);

}
