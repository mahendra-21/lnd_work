/* function for printing the account holder names */

#include <header.h>

int print_acc_hldr_names (struct bank *data, int start) {

    static int list = 1;

    if (0 == list) return 0;

    if ('\0' == data) return 0;

    //    puts("Bank Account Holder details's are:");
    //    puts("S.NO\tNAME\t\t\tAC_TYPE\t\tAC_NUMBER\t\tBALANCE");

    printf("%d\t%s\t", list, data[start].account_holder_name);
    printf("\t%s\t\t%s\t", data[start].account_type, 
            data[start].account_number);
    printf("%ld\n", data[start].balance);


    list++;

    return 1;
}
