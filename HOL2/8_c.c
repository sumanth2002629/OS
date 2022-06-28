//Program Number:8
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: Signals

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sigfpe_handler(int sig);
int main()
{
    //Catching SIGFPE signal
    signal(SIGFPE,sigfpe_handler);
    int x = 1/0; //generates SIGFPE 
}

void sigfpe_handler(int sig)
{
    printf("SIGFPE has been received\n");
    exit(0);
}