#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process PID: %d\n", getpid());
        printf("Child process PPID: %d\n", getppid());
        exit(7);
    }
    else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child exited with status: %d\n", WEXITSTATUS(status));
        }

        printf("Parent process PID: %d\n", getpid());
        printf("Parent process PPID: %d\n", getppid());
    }

    return 0;
}