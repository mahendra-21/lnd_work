/**
 *  @file
 *  @brief implementing own size of operator macror
 *
 *  @var char $ch
 *  @author
 */
#include <stdio.h>

#define SIZEOF(obj) ((char *) (&obj + 1)) - ((char *) &obj)

int main(void)
{
    char ch;
    unsigned int a = 10;

    printf("size -> %d\n", SIZEOF(ch));

//    if (-1 <  a)
//        printf("hello\n");

    return 0;
}
