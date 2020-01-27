/*
   Insertion in Double linked list:
   1. Insert at the beginning
   2. Insert at the end
   3. Insert at a given position
   4. Insert before a given position
   5. Insert after a given position
   6. Insert before a given number
   7. Insert after a given number
   8. Insert at the middle
   9. Insert at penultimate node.

 */

#include <header.h>

int dll_insert_switch(void)
{
    DL *hptr = NULL;;

    int option = 0;
    int ret = 0;
    int pos = 0;

    system("clear");
    while (1) {
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("INSERTION IN DOUBLE LINKED LIST:\n"
               "    0. Exit from DLL Insertion operation's\n"
               "    1. Insert at the beginning\n"
               "    2. Insert at the end\n"
               "    3. Insert at a given position\n"
               "    4. Insert before a given position\n"
               "    5. Insert after a given position\n"
               "    6. Insert before a given number\n"
               "    7. Insert after a given number\n"
               "    8. Insert at the middle\n"
               "    9. Insert at penultimate node\n"
               "   10. Display the list.\n"
               "Enter the option: ");
        option = get_number();

        switch (option) {

            case    1:
                ret = dll_insert_begin(&hptr);
                if (FAILURE == ret) {
                    printf("Node is not created\n");
                    return 0;
                }
                break;

            case    2:
                ret = dll_insert_end(&hptr);
                if (FAILURE == ret) {
                    printf("Node is not created\n");
                    return 0;
                }
                break;

            case    3:
                printf("Enter the position: ");
                pos = get_number();
                ret = dll_insert_at_given_pos(&hptr, pos);
                if (FAILURE == ret) {
                    printf("Node is not created\n");
                    return 0;
                }
                break;

            case    4:
                ret = dll_insert_before_given_pos(&hptr);
                if (FAILURE == ret) {
                    printf("Node is not created\n");
                    return 0;
                }
                break;

            case    5:
                ret = dll_insert_after_given_pos(&hptr);

                if (FAILURE == ret) {
                    printf("Node is not created\n");
                    return 0;
                }

                break;
 /*           case    6:
                ret = dll_insert_before_given_number(&hptr);

                if (FAILURE == ret) {
                    printf("Node is not created\n");
                    return 0;
                }

                break;
            case    7:
                ret = dll_insert_after_given_number(&hptr);

                if (FAILURE == ret) {
                    printf("Node is not created\n");
                    return 0;
                }

                break;
  */          case   10: system("clear");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("List contains:\n");
                ret = dll_display_list(hptr);
                if (SUCCESS == ret) continue;
                if (FAILURE == ret) {
                    printf("    Nothing....!\n");
                    continue;
                }
                break;
                
            case    0: return 0;
            default  : system("clear");
                printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
                printf("Incorrect option ----> Enter again\n");
                continue;
        }
        system("clear");    
    }

    return 0;
}
