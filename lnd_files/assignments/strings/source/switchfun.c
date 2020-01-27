/* swaitch function */

#include <string_header.h>

void switch_fun (int option) {

    char string[SIZE] = {0};
    char src[SIZE] = {0};
    char dest[SIZE] = {0};

    int number = 0;
    
    switch (option) {

        case 1 : 
            puts("enter a source string:");
            

            puts("enter a number to copy n characters from src to dest:");
            number = get_number();

            my_strncpy (dest, src, number);

            puts(dest);

            break;

    }

}
