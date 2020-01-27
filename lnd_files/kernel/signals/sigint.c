#include <stdio.h>
#include <signal.h>

void IntHandler(int var) {
    printf("var -> %d\n", var);
    printf("IN Signal Handler\n");
    return;
}

int main(void)
{
    signal(SIGINT, IntHandler);
    signal(SIGQUIT, IntHandler);
    printf("In main function\n");
 getchar();   
//  raise(SIGINT);
    return 0;
}
