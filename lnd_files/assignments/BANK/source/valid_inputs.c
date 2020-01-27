/* validadting the user inputs */

#include <header.h>

int validation_acc_hld_name (char *rawdata) {

    if (NULL == rawdata) return 0;
    
    while ('\0' != *rawdata) {

        if ((('a' <= *rawdata) && ('z' >= *rawdata)) 
                || (('A' <= *rawdata) && ('Z' >= *rawdata)) 
                || (' ' == *rawdata)) {

            if (' ' != *rawdata) {
                *rawdata = *rawdata &~ 32;
            }
                      
            rawdata++;
            continue;
        } else if ('\n' == *rawdata) {
            *rawdata = *(rawdata + 1);
            continue;
        } else {
            return 0;
        }

    }

    return 1;
}

int validation_account_type (char *rawdata) {

    if (NULL == rawdata) return 0;

    while ('\0' != *rawdata) {
    puts("after in while");

        if ((('a' <= *rawdata) && ('z' >= *rawdata)) 
                || (('A' <= *rawdata) && ('Z' >= *rawdata))) {

            *rawdata = *rawdata | 32;
    puts("after in if");
            rawdata++;
            continue;
        } else if ('\n' == *rawdata) {
    puts("after in else if");
            *rawdata = *(rawdata + 1);
            continue;
        } else {
            return 0;
        }
    
    }
    puts("after while");
 
    return 1;
}

int validation_account_number (char *rawdata) {

    int count = 0;
    puts("in function");
    if (NULL == rawdata) return 0;

    while ('\0' != *rawdata) {
    puts("in while");

        if (('0' <= *rawdata) && ('9' >= *rawdata)) {
            puts("in if");

            if ((count > NMAX) || (count < NMAX)) {
                return 0;
            }

            count++;
            rawdata++;
            continue;
        } else if ('\n' == *rawdata) {
            puts("in else if");
            *rawdata = *(rawdata + 1);
            continue;
        } else {
            puts("in else");
            return 0;
        }
    
    }
 
    return 1;
}

int validation_balance (long int balance) {

    if (balance > 10000000) {
        return 0;
    }

    return 1;
}
