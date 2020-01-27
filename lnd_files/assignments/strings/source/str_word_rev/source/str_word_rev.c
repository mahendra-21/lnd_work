/* Function for string reverse with out taking temp buff */
#include "header.h"

char *strin_out(char *str)
{
    int start = 0;
    int help = 0;
    int len = 0;

    for (len = 0; str[len]; len++);
    
    my_strrev(str, len, start);
    
    for (start = 0, len = 0; str[start]; start++, len++)
    {
  
        if (' ' == str[start]) {
            my_strrev(str, len , help);
            help = start + 1;
        } else if ('\0' == str[start + 1]) 
            my_strrev(str, len + 1, help);
 
    }
    
    return str; 
}
