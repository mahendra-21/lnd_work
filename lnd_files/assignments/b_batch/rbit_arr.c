#include <stdio.h>

int main()
{
    int size  = 0;

    printf("enter array size:");
    scanf("%d", &size);

    int arr[size];
    int start = 0;
    int end = 0;
    int count = 0;

    puts("enter the elements of an array");
    for (start = 0; size > start; start++) {
        scanf("%d", &arr[start]);
    }
    
    printf("unique numbers is : ");
    for (start = 0; size > start; start++) {

        count = 0;

        for(end = 0; size > end; end++) {
            
            if ((arr[start] ^ arr[end]) == 0) {
                
                count++;

            }

        }

        if(count == 1) {

            printf("%d  ", arr[start]);

        }

    }

    printf("\n");

}
