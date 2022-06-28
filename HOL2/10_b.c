//Program Number:10
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: signals


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void segfault_handler(int sig);
int main()
{
    int i;
    struct sigaction sac;
    sac.sa_handler = segfault_handler;
    sigaction(SIGINT, &sac,NULL);
    printf("Press Ctrl C to generate SIGINT\n");
    for(;;);
}

void segfault_handler(int sig)
{
    printf("SIGINT has occured\n");
    exit(0);
}