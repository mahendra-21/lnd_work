/* Validating the fgets function.
   Return Values: Upon success this function returns 1 other-wise 
   it returns zero(0) */

#include <stdio.h>

int validating_fgets (char *rawdata) {

    if (NULL == rawdata) return 0;

    while ('\0' != *rawdata) {
        /* If '\n' is occured in the raw-data removing the '\n' in the 
           raw-data */
        if ('\n' == *rawdata) {
            *rawdata = *(rawdata + 1); 
            continue;
        }

        rawdata++;
    }

    return 1;
}
