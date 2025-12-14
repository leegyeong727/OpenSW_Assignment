#include <stdio.h>
#include <unistd.h>

int main(void)
{
    while (1)
    {
        printf("Process ID: %d\n", getpid());
        sleep(1);
    }

    return 0;
}

