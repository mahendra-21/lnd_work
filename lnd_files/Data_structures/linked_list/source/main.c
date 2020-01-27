#include <header.h>

int main(void)
{
    int choice = 0;
    int ret = 0;

    while (1) {
        system("clear");
        printf("\n~~~~~~~~~~~~  **** LINKED LIST ****  ~~~~~~~~~~~~\n");
        printf("    1. Single linked list Insert operation's\n"
               "    2. Single linked list Delete operation's\n"
               "    3. Double linked list Insert operation's\n"
               "    4. Double linked list Delete operation's\n"
               "    0. EXIT\n"
               "----> Enter the option which operation's to do: ");      
        choice = get_number();
        system("clear");

        switch (choice) {
            case    1:
                ret = sll_insert_switch();
                if (0 == ret) continue;
                break;
            case    2:

            case    3:
                ret = dll_insert_switch();
                if (0 == ret) continue;
                break;

            case    4:

            case    0:
                return 0;

            default  : system("clear");
                printf("Invalid choice ---> Enter again\n");
                break;
        }

    }

    return 0;
}
