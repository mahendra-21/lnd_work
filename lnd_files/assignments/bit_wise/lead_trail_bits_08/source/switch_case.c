/* switch case for selecting the which operation has to be perform */

#include <header.h>

void switch_fun(unsigned int num) { 

    unsigned int temp = 0;
    char ch = NULL;
    unsigned int choice = 0;   

    do {
    
        puts("1. count leading set bits");
        puts("2. count leading cleared bits");
        puts("3. count trailing set bits");
        puts("4. count trailing cleared bits");
        puts("5. exit");

        puts("*** Enter the choice ***");
        scanf("%d", &choice);
        
        if (5 == choice) {

            exit (0);

        }

        printf("Before rotation number is ---> %u\n", num);
        binary_print(num);

        puts("**********************************************");

        switch (choice) {
            case 1:
                puts("<--- the number of leading set bits  --->");
                temp = cnt_leading_set_bits (num);
                break;
            case 2: 
                puts("<--- the number of leading cleared bits  --->");
                temp = cnt_leading_cleared_bits (num);
                break;
            case 3:  
                puts("<--- the number of trailing set bits  --->");
                temp = cnt_trailing_set_bits (num);
                break;
            case 4: 
                puts("<--- the number of trailing cleared bits  --->");
                temp = cnt_trailing_cleared_bits (num);
                break;
            default:
                puts("*** enter correct choice < 1 to 5 > ***");
                break;
        }
        
        printf("count = %d\n", temp);

        puts("**********************************************");


        puts("Do you want to do one more opeartion ---> press(y)"
                " otherwise ---> press(n)");
        scanf(" %c", &ch);
 
    } while (('Y' == ch) || ('y' == ch));

}


