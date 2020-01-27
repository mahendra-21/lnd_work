/* Function to convert ascii to an integer value */
#include "../HEADER/header.h"
int myatoi(char *s)
{
    int sign;
    int n = 0;

    for(; isspace(*s);s++);

    sign = (*s == '-' ? -1 : 1);

    if(*s == '-' || *s == '+')
        s++;

    for(;isdigit(*s);s++)
        n = n * 10 + (*s - '0');

    return (sign * n);

}

