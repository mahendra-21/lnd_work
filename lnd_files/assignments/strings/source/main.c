/* String Assignments(02) */
#include <string_header.h>

int main()
{
    int option = 0;

    /* Asking user which string operation has to perform */
    puts(" 1. strncpy     2. sappend     3. snappend     4. strcmp");
    puts(" 5. strspn      6. strtok      7. strrev       8. char_squeeze");
    puts(" 9. strrot     10. remsstr    11. insertchar  12. conse_occ_3ones");
    puts("13. vertical histogram");
    puts("Enter your Option:");

    option = get_number();

    switch_fun(option);

    return 0;

}
