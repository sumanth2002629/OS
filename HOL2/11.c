//Program Number:11
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: Signals


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    struct sigaction sac;
    sac.sa_handler = SIG_IGN;
    sigaction(SIGINT, &sac,NULL);
    printf("Ignoring SIGINT\n");
    sleep(5);

    sac.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sac,NULL);
    printf("Default for SIGINT\n");
    sleep(5);

    return 0;
}