/* switch case for selecting the which operation has to be perform */

#include <header.h> // including the user defined header

/* function definition for switch function and it 
   is taking one unsigned integer as argument */
void switch_fun() { 

    unsigned int num1 = 0;
    unsigned int num2 = 0;
    unsigned int num = 0;
    unsigned int spos = 0;
    unsigned int dpos = 0;
    
    char ch = NULL;

    unsigned int choice = 0;   

    do {
    
        puts("1. maximum and minimum of 2 numbers");
        puts("2. clear right most set bit in a number");
        puts("3. clear left most set bit in a number");
        puts("4. right most cleared bit in a number");
        puts("5. left most cleared bit in a number");
        puts("6. set bits from spos --> dpos & clear rest bits");
        puts("7. clear bits from spos --> dpos & set rest bits");
        puts("8. toggle bits from spos --> dpos");

        puts("*** Enter the choice ***");
        scanf("%d", &choice); 
           
        switch (choice) {
            case 1:
                puts("enter the first number:");
                num1 = get_number();
                puts("enter the second number:");
                num2 = get_number();
                min_max(num1, num2);
                break;
            case 2:
                puts("enter a number:");
                num = get_number();
                
                printf("Actual number is ---> %u\n", num);
                binary_print(num);
        
                num = clear_right_most_setbit(num);
                
                printf("Modifide number is ---> %u\n", num);
                binary_print(num);
                break;
            case 3:  
                puts("enter a number:");
                num = get_number();
                
                binary_print(num);
                printf("Actual number is ---> %u\n", num);
        
                num = clear_left_most_setbit(num);
                
                printf("Modifide number is ---> %u\n", num);
                binary_print(num);
                break;
            case 4: 
                puts("enter a number:");
                num = get_number();
        
                printf("Actual number is ---> %u\n", num);
                binary_print(num);
               
                num = set_right_most_clearedbit(num);
                
                printf("Modifide number is ---> %u\n", num);
                binary_print(num);
                break;
            case 5: 
                puts("enter a number:");
                num = get_number();
        
                printf("Actual number is ---> %u\n", num);
                binary_print(num);
                
                num = set_left_most_clearedbit(num);
                
                printf("Modifide number is ---> %u\n", num);
                binary_print(num);
                break;
            case 6: 
                puts("enter a number:");
                num = get_number();
                puts("enter source position:");
                spos = get_number();
                puts("enter destination position:");
                dpos = get_number();
        
                printf("Actual number is ---> %u\n", num);
                binary_print(num);
                
                num = set_clear_bits(num, spos, dpos);
                
                printf("Modifide number is ---> %u\n", num);
                binary_print(num);
                break;
            case 7: 
                puts("enter a number:");
                num = get_number();
                puts("enter source position:");
                spos = get_number();
                puts("enter destination position:");
                dpos = get_number();
    
                printf("Actual number is ---> %u\n", num);
                binary_print(num);

                num = clear_set_bits(num, spos, dpos);
                
                printf("Modifide number is ---> %u\n", num);
                binary_print(num);
                break;
            case 8: 
                puts("enter a number:");
                num = get_number();
                puts("enter source position:");
                spos = get_number();
                puts("enter destination position:");
                dpos = get_number();
        
                printf("Actual number is ---> %u\n", num);
                binary_print(num);
                
                num = toggle_bits(num, spos, dpos);
                
                printf("Modifide number is ---> %u\n", num);
                binary_print(num);
                break;
            default:
                puts("*** enter correct choice < 1 to 8 > ***");
                break;
        }

               
        puts("**********************************************");
        
        puts("Do you want to do one more opeartion ---> press(y)"
                " otherwise ---> press(n)");
        scanf(" %c", &ch);
 
    } while (('Y' == ch) || ('y' == ch));

}


