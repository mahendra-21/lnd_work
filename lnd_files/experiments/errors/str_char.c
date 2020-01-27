#include <stdio.h>

int main(void)
{
#if 1
    printf('\n');
    printf("hello, Global");
    printf("\n");

    return 0;
#endif

#if 0
    char cvar = "mahi";

    printf ("char = %c\n", cvar);
    printf ("char_num = %d\n", cvar);

    return 0;
#endif

#if 0    
    char *string = 'mahendra';

    printf ("str = %s\n", string);
    printf ("str_char = %c\n", string);
    printf ("str_num = %d\n", string);

    return 0;
#endif

#if 0   
    char cvar = "mahi";
    char chvar = 'mahi';

    printf ("cavr = %s\tchvar = %c\n", cvar, chvar);
    
    return 0;
#endif
}
