#include <stdio.h>

#if 0
int main(void) 
{
    float fvar = 1.25;
    printf("float = %f\n", fvar);
    if (fvar == 1.25) {
        puts("yes");
    } else {
        puts("no");
    }
    
    return 0;
}
#endif

#if 1
int main(void) 
{
    float fvar = 1.26;
    printf("float = %f\n", fvar);
    if (fvar == 1.26) {
        puts("yes");
    } else {
        puts("no");
    }
    
    return 0;
}
#endif
