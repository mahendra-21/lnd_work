#include <header.h>

int *start = NULL;
int *last = NULL;
int index = -1;

int main(void)
{
    int option = 0;
    int number = 0;
    int ret = 0;

    int queue[SIZE] = {0};
    
    puts("<-------      QUEUE OPERATION       ------>");
    while (1) {
        puts("Enter the option:");
        puts("  1. Enqueue");
        puts("  2. Dequeue");
        puts("  3. Display the queue");
        puts("  4. EXIT");

        option = get_number();

        switch (option) {

            case ENQUE    : puts("<-----        ENQUEUE       ----->");
                            printf("Enter the number to enqueue into Queue:");
                            number = get_number();
                            ret = enqueue(queue, number);
                                
                            if (0 == ret) {
                                puts("---->  QUEUE is full");
                                break;
                            }

                            printf("queue[%d] = %d\n", index, ret);
                            break;

            case DEQUE    : puts("<-----        DEQUEUE       ----->");
                            ret = dequeue(queue);
                            
                            if (0 == ret) {
                                puts("----->  Queue is empty");
                                break;
                            }
                            
                            printf("Dequeued element is %d\n", ret);
                            break;

            case DISPLAY  : puts("<----- DISPLAYING THE QUEUE ----->");
                            display(queue);
                            break;

            case EXIT     : puts("<----      THANK YOU...!     ---->");  
                            return 0;

            defualt       : puts("Etered Invalid Option");
                            break;
        }
        puts("<------------------------------------------------>");
    }

    return 0;
}
