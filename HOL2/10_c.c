//Program Number:10
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: Signals


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
    sigaction(SIGFPE, &sac,NULL);
    int x = 1/0; //generates SIGFPE 
}

void segfault_handler(int sig)
{
    printf("SIGFPE has occured\n");
    exit(0);
}