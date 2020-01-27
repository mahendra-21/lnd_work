#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (2 != argc) {
        printf("Usage: %s <number> \n", argv[0]);
        return 0;
    }

    int num;
    int tmp_num;
    int loop;
    
    num = atoi(argv[1]);

    for (loop = 1; num > loop; loop++) {

        if (((num / loop) == loop) && ((num % loop) == 0)) {
            printf("--> %d square root is %d\n", num, loop);
            return 0;
        }
    }

    if (loop == num)
        printf("--> %d doesn't have any square root\n", num);

    return 0;
}
