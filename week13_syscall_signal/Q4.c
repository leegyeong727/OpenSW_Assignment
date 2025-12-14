#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

void sigint_handler(int signum)
{
    pid_t pid;
    printf("[SIGINT handler] ------------\n");

    pid = fork();
    if (pid == 0) {
        char *argv[] = { "ls", NULL };
        execve("/usr/bin/ls", argv, NULL);
        exit(1);
    } else {
        wait(NULL);
    }
}

void sigquit_handler(int signum)
{
    pid_t pid;
    printf("[SIGQUIT handler] ------------\n");

    pid = fork();
    if (pid == 0) {
        char *argv[] = { "date", NULL };
        execve("/usr/bin/date", argv, NULL);
        exit(1);
    } else {
        wait(NULL);
    }
}

void sigalrm_handler(int signum)
{
    pid_t pid;
    printf("[SIGALRM handler] ------------\n");

    pid = fork();
    if (pid == 0) {
        char *argv[] = { "whoami", NULL };
        execve("/usr/bin/whoami", argv, NULL);
        exit(1);
    } else {
        wait(NULL);
    }

    alarm(3);
}

int main(void)
{
    signal(SIGINT,  sigint_handler);
    signal(SIGQUIT, sigquit_handler);
    signal(SIGALRM, sigalrm_handler);

    alarm(3);

    while (1) {
        sleep(1);
    }

    return 0;
}
