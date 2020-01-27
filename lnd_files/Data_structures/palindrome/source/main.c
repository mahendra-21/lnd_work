#include <header.h>

int main(void)
{
    SL *hptr = NULL;
    system("clear"); 
    printf("Enter the number: ");
    int number = get_number();
    int temp = number;
    int help = 0;
    int ret = 0;

    while (temp) {
        help = 0;
        help = temp % 10;
        ret = insert_begin(&hptr, help);

        if (FAILURE == ret) {
            printf("Node not created\n");
            exit(0);
        }

        temp /= 10;
    }

    printf("BEFORE LIST IS:\n");
    display_list(hptr);
    printf("<---------------------------------------->\n");
    int count = node_count(&hptr);

    if (1 == count) {
        printf("----->  Given Number Is PALINDROME\n");
    } else if (2 == count) {

        if ((hptr -> data) != (hptr -> link -> data)) {
            printf("-----> Given Number Is Not PALINDROME\n");
            help = hptr -> data;
            hptr -> data = hptr -> link -> data;
            hptr -> link -> data = help;
        } else {
            printf("----->  Given Number Is PALINDROME\n");
        }
        printf("<---------------------------------------->\n");
        printf("AFTER LIST IS:\n");
        display_list(hptr);

    } else if (SUCCESS == (palin_check(hptr, count))) {
        printf("----->  Given Number Is PALINDROME\n");
    } else {
        printf("-----> Given Number Is Not PALINDROME\n");
   
        reverse_list(hptr);
        
        printf("<---------------------------------------->\n");
        printf("AFTER LIST IS:\n");
        display_list(hptr);
    }
    return 0;
}
