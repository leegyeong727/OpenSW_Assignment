#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <program path> [OPTION]...\n", argv[0]);
        exit(1);
    }

    pid_t pid = fork();
    int status;

    if (pid < 0) {
        perror("fork");
        exit(1);
    }
    else if (pid == 0) {
        execve(argv[1], &argv[1], NULL);

        perror("execve");
        exit(1);
    }
    else {
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            printf("Child exit code: %d\n", WEXITSTATUS(status));
        }
    }

    return 0;
}
