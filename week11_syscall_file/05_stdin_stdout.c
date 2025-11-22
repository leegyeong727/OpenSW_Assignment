#include <stdio.h>
#include <unistd.h>

int main(void)
{
    char buffer[128];
    ssize_t n;

    while (1) {

        n = read(STDIN_FILENO, buffer, sizeof(buffer));

        if (n == 0) {
            printf("\nDetected EOF (Ctrl + D)\n");
            printf("Terminating read loop...\n");
            break;
        }

        if (n < 0) {
            perror("read");
            break;
        }

        if (write(STDOUT_FILENO, buffer, n) < 0) {
            perror("write");
            break;
        }
    }

    return 0;
}
