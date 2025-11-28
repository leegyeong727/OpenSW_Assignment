#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(const char *command) {
    pid_t pid;
    int status;

    if (command == NULL) return 1; 

    pid = fork();

    if (pid < 0) {
        perror("fork");
        return -1;
    }
    else if (pid == 0) {
        execl("/bin/sh", "sh", "-c", command, (char *)NULL);

        perror("execl");
        exit(1);
    }
    else {
        waitpid(pid, &status, 0);
        return status;
    }
}

int main(void) {

    mysystem("ls -l | wc -l");
    mysystem("find . -name \"*.c\"");

    printf("Good Bye~\n");

    return 0;
}
