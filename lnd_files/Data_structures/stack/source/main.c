/* Implementing the STACK in LIFO (last in first out) manner */

#include <header.h>

int top = -1;

int main(void)
{
    int stack[SIZE] = {0};

    int option = 0;
    int number = 0;
    int ret = 0;
    puts("<---------------  STACK OPERATION  --------------->");
    while (1) {
        puts("Enter the option:");
        puts("  1. Push into stack");
        puts("  2. Pop in stack");
        puts("  3. Display the stack");
        puts("  4. peak of the stack");
        puts("  5. stack is full or not");
        puts("  6. stack is empty or not");
        puts("  7. EXIT");

        option = get_number(); 

        switch (option) {
            case PUSH    : puts("<---  PUSHING VALUE INTO THE STACK --->");
                           printf("Enter the number to push into the stack: ");
                           number = get_number();
                           ret = push(stack, number);
                           printf("stack[%d] = %d\n", top, ret);
                           break;

            case POP     : puts("<--    POPED VALUE IN THE STACK   --->");
                           ret = pop(stack);
                           printf("poped value in stack is %d\n", ret);
                           break;

            case DISPLAY : puts("<--------    DISPLAYING STACK   ------>");
                           display(stack);
                           break;

            case PEAK    : puts("<-----  PEAK POSITION OF STACK   ----->");
                           peak();
                           break;

            case ISFULL  : puts("<----    IS STACK FULL OR NOT     ---->");
                           isfull();
                           break;

            case ISEMPTY : puts("<----    IS STACK EMPTY OR NOT    ---->");
                           isempty();
                           break;

            case EXIT    : puts("<-----       THANK YOU...!       ----->"); 
                           return 0;

            default      : puts("Enter correct option");
                           break;
        }
        puts("<--------------------------------------------->");
    }

    return 0;
}
