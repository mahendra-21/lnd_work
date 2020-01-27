/* validadting the user inputs */

#include <header.h>

int validation_acc_hld_name (char *rawdata) {

    if (NULL == rawdata) return 0;

    while ('\0' != *rawdata) {

        if ((('a' <= *rawdata) && ('z' >= *rawdata)) 
                || (('A' <= *rawdata) && ('Z' >= *rawdata)) 
                || ' ' == *rawdata) {
            
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

        if ((('a' <= *rawdata) && ('z' >= *rawdata)) 
                || (('A' <= *rawdata) && ('Z' >= *rawdata))) {
            *rawdata = *rawdata | 32;
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

int validation_account_number (char *rawdata) {

    int count = 1;

    if (NULL == rawdata) return 0;

    while ('\0' != *rawdata) {

        if (('0' <= *rawdata) && ('9' >= *rawdata)) {
            
            if (count > NMAX) {
                return 0;
            }

            count++;
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

int validation_balance (long int balance) {

    if (balance > 10000000) {
        return 0;
    }

    return 1;
}
