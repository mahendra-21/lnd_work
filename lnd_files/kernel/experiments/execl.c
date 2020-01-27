#include <stdio.h>
#include <unistd.h>

int main(void)
{
    execlp("", "date", (char *)NULL);
}
