#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

struct two_double {
    double a;
    double b;
};

struct two_double data;

void sigint_handler(int _signo)
{
    printf("%d, %d\n", (int)data.a, (int)data.b);
    alarm(1);
}

int main(void)
{
    struct sigaction sa_sigalrm;
    struct two_double zeros = {0.0, 0.0};
    struct two_double ones  = {1.0, 1.0};

    sigset_t block_set, prev_set;

    sa_sigalrm.sa_handler = sigint_handler;
    sigemptyset(&sa_sigalrm.sa_mask);
    sa_sigalrm.sa_flags = 0;

    if (sigaction(SIGALRM, &sa_sigalrm, NULL) == -1) {
        perror("sigaction error");
        exit(1);
    }

    sigemptyset(&block_set);
    sigaddset(&block_set, SIGALRM);

    alarm(1);

    while (1) {
        sigprocmask(SIG_BLOCK, &block_set, &prev_set);
        data = zeros;
        sigprocmask(SIG_SETMASK, &prev_set, NULL);
        sigprocmask(SIG_BLOCK, &block_set, &prev_set);
        data = ones;
        sigprocmask(SIG_SETMASK, &prev_set, NULL);
    }

    return 0;
}
