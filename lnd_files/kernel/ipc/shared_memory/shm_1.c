#include "../../header.h"

int main(void)
{
    const char* name = "mahi"; /*name of the shm object */

    const char* msg1 = "hello";
    const char* msg2 = "global";

    int shm_fd; /* shm file descriptor */
    char* ptr; /* poiter to shm object */

    /* Create the shm object */
    shm_fd = shm_open(name, O_CREAT | O_RDWR, 0666);

    /* Configure the size of the shm object */
    ftruncate(shm_fd, SIZE);

    /* memory map the shared memory object */
    ptr = mmap(0, SIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    /* write to the shared memory object */
    sprintf(ptr, "%s", msg1); 

    ptr += strlen(msg1); 
    sprintf(ptr, "%s", msg2); 
    ptr += strlen(msg2); 
    getchar();
    return 0; 
} 
