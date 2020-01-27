#include "../../header.h"

int main(void) 
{
    /* name of the shared memory object */
    const char* name = "mahi"; 

    /* shared memory file descriptor */
    int shm_fd; 

    /* pointer to shared memory object */
    char* ptr; 

    /* open the shared memory object */
    shm_fd = shm_open(name, O_RDONLY, 0666); 

    /* memory map the shared memory object */
    ptr = mmap(0, SIZE, PROT_READ, MAP_SHARED, shm_fd, 0); 

    /* read from the shared memory object */
    printf("%s\n", (char*)ptr); 
    getchar();
    /* remove the shared memory object */
    shm_unlink(name); 
    return 0; 
} 
