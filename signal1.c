#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

void sigHandler(int sig)
{
    printf("SIGUSR1\n");
}

void sig2Handler(int sig)
{
    printf("SIGUSR2\n");
    exit(1);
}

int main()
{
    struct sigaction usr2;
    usr2.sa_handler = sig2Handler;
    usr2.sa_flags = 0;
    sigemptyset(&usr2.sa_mask);
    sigaddset(&usr2.sa_mask, SIGUSR2);
    sigaction(SIGUSR2, &usr2, 0);
    signal(SIGUSR1, sigHandler);
    while(1);
}
