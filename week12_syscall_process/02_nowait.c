#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void) {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child PID: %d\n", getpid());
        printf("Child PPID(before): %d\n", getppid());
        sleep(1);
        printf("Child PPID(after): %d\n", getppid());
        exit(0);
    }
    else {
        printf("Parent PID: %d\n", getpid());
        printf("Parent PPID: %d\n", getppid());
        exit(0);
    }
}
