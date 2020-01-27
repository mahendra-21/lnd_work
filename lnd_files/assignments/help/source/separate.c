/* function for printing the lessthan Rs 1000 Account holders details */

int print_less_balance_names (struct bank *details, int list) {
    
    static int s_var = 1; //
    int balance = 0;

    if ('\0' == details) return 0;
    
    if (1000 > details[list].balance) {

        balance = details[list].balance;

        details[list].balance = details[list].balance - 100;

        printf("%d\t%s\t\t\t%s\t\t%s\t\t%d\t\t%d\n", s_var, 
            details[list].account_holder_name, details[list].account_type,
            details[list].account_number, balance, details[list].balance);
        
        s_var++;
    }

    return 1;
}

/* function for printing the greaterthan Rs 1000 Account holders details */
    
int print_more_balance_names (struct bank *details, int list) {
    
    static int s_var = 1;
    int balance = 0;

    if ('\0' == details) return 0;
    
    if (1000 <= details[list].balance) {

        balance = details[list].balance;

        details[list].balance = details[list].balance + 100;

        printf("%d\t%s\t\t\t%s\t\t%s\t\t%d\t\t%d\n", s_var, 
            details[list].account_holder_name, details[list].account_type,
            details[list].account_number, balance, details[list].balance);
        
        s_var++;
    }

    return 1;
}
