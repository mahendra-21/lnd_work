/* append string str1 to string str2 */
#include <stdio.h>
#include <stdlib.h>

void sappend(const char *str1, char *str2) {

    while (*str2)  str2++;

    while (*str1)  *str2++ = *str1++;    

    *str2 = *str1;

}

int main(void)
{
    char *ptr = (char *) malloc(127);
    char *str = (char *) malloc(127);
    
    printf("enter src string:");
    fgets(ptr, 127, stdin);
    __fpurge(stdin);

    char *temp = ptr;
    while ('\n' != *temp) temp++;
    *temp = *(temp + 1);
    
    printf("enter dst string:");
    fgets(str, 127, stdin);
    __fpurge(stdin);
   
    temp = str;
    while ('\n' != *temp) temp++;
    *temp = *(temp + 1);

    sappend(ptr, str);
    
    printf("str -> %s\n", str);
    return 0;
}
