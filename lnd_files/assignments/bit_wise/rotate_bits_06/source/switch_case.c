/* switch case for selecting the which operation has to be perform */


#include <header.h>

void switch_fun(unsigned int num, unsigned int pos) { 

    unsigned int temp = 0;
    char ch = NULL;
    unsigned int choice = 0;   

    do {
    
        puts("1. left_rotate_bits");
        puts("2. right_rotate_bits");
        puts("3. left_rotate_n_bits");
        puts("4. right_rotate_n_bits");
        puts("5. exit");

        puts("*** Enter the choice ***");
        scanf("%d", &choice);
        
        if (5 == choice) {

            exit (0);

        }

        printf("Before rotation number is ---> %u\n", num);
        binary_print(num);

        switch (choice) {
            case 1:
                puts("--- left rotating the number num ---");
                temp = r_left(num);
                break;
            case 2: 
                puts("--- right rotating the number num ---");
                temp = r_right(num);
                break;
            case 3:  
                puts("--- left rotating the number num by n bits ---");
                temp = r_nbits_left(num, pos);
                break;
            case 4: 
                puts("--- right rotating the number num by n bits ---");
                temp = r_nbits_right(num, pos);
                break;
            default:
                puts("*** enter correct choice < 1 to 5 > ***");
                break;
        }

        puts("**********************************************");
        
        printf("After rotation number is ---> %u\n", temp);
        binary_print(temp);

        puts("**********************************************");

        puts("Do you want to do one more opeartion ---> press(y)"
                " otherwise ---> press(n)");
        scanf(" %c", &ch);
 
    } while (('Y' == ch) || ('y' == ch));

}


