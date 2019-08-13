#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
    int sig = 0;
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGUSR2);
    sigaddset(&mask, SIGUSR1);
    sigprocmask(SIG_BLOCK, &mask, NULL);
    while(1)
    {
        sigwait(&mask, &sig);
        if(sig == SIGUSR2)
        {
            printf("SIGUSR2\n");
        }
        if(sig == SIGUSR1)
        {
            exit(1);
        }
    }
}
