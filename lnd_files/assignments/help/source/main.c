/* Bank details */
#include <header.h>

int main(void)
{
    int list = 0;
    int start = 0;
    int ret = 0;

    puts("enter howmany people details you want to enter:");
    list = get_number();

    struct bank details[list];
    /***                INPUTS                  ***/    
    for (start = 0; start < list; ) {

        system("clear");

        puts("Enter Account Holder Name:");
        fgets(details[start].account_holder_name, MAX, stdin);
        fflush(stdin);

        ret = validation_acc_hld_name (details[start].account_holder_name);

        if (0 == ret) {
            puts("*** Invalid Account Holder Name ***");
            start = start;
            continue;
        }

        puts("Enter Account Type (savings/current):");
        fgets(details[start].account_type, MAX, stdin);
        fflush(stdin);

        ret = validation_account_type (details[start].account_type);

        if (0 == ret) {
            puts("*** Invalid Account Type ***");
            start = start;
            continue;
        }

        puts("Enter Account Number (should be 10 digits):");
        fgets(details[start].account_number, MAX, stdin);
        fflush(stdin);

        ret = validation_account_number (details[start].account_number);

        if (0 == ret) {
            puts("*** Invalid Account Number ***");
            start = start;
            continue;
        }

        puts("Enter Account Balance (should be with in 10000000(1 crore)):");
        details[start].balance = get_number();

        ret = validation_balance (details[start].balance);

        if (0 == ret) {
            puts("*** my bank can't accepts huge amount ***");
            start = start;
            return 0;
        }

        __fpurge(stdin);

        start++;

    }
    /***            OUTPUTS             ***/

    puts("Bank Account Holder details's are:");
    puts("S.NO\tNAME\t\tAC_TYPE \tAC_NUMBER \tBALANCE");

    for (start = 0; start < list; start++) {

        ret = print_acc_hldr_names (details, start);

        if (0 == ret) {
            puts("In Bank doesn't have any account holders");
            return 0;
        }

    }

    //    ret = print_less_amt_names (

    return 0;
}
