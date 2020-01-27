/* function for printing the account holder names */

#include <header.h>

int print_acc_hldr_names (struct bank *data, int list) {
    
    int start = 1;

    if (0 == list) return 0;

    if ('\0' == data) return 0;
    
    puts("Bank Account Holder details's are:");
    puts("S.NO\tNAME\t\t\tAC_TYPE\t\tAC_NUMBER\t\tBALANCE");
    while (start <= list) {
        printf("%d\t%s\t\t\t%s\t\t%s\t\t%ld\n", start, 
            data[start].account_holder_name, data[start].account_type, 
            data[start].account_number, data[start].balance);
        data++;
        start++;
    }

    return 1;
}
