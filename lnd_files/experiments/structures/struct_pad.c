#include <stdio.h>
#if 1
struct tag {
    char cvar;
} var;
struct tag1 {
    struct tag var;
    int ivar;
} var1; 

int main(void)
{
    printf("size = %d\n", sizeof(var1));

    return 0;
}
#endif

#if 0

struct tag {
    int ivar;
    char cvar;
    short svar;
    double dvar;
    char cvar1;
    int ivar1;
    double dvar1;
} var;

int main(void)
{
    printf("size = %d\n", sizeof(var));

    return 0;
}
#endif

#if 0 

struct pad {
    short svar;
    char cvar;
    float fvar;
    double dvar;
    int ivar;
    char cvar1;
    short svar1;
}ding;

struct pad1 {
    struct pad ding;
    char cvar1;
    double dvar;
    char cvar2;
    float fvar;
    int ivar3;
} ding1;

int main(void)
{

    printf("size of ding in main  = %d\n", sizeof (ding));
//    printf("size of ding in main  = %d\n", sizeof (ding1));

    return 0;
}
#endif
