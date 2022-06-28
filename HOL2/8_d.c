//Program Number:8
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: Signals


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sigalrm_handler(int sig);
int main()
{
    //Catching SIGALRM signal
    signal(SIGALRM,sigalrm_handler);
    alarm(5);  //SIGALRM will received in 5 seconds.
    for(;;);
   
}

void sigalrm_handler(int sig)
{
    printf("SIGALRM has been received\n");
    exit(0);
}