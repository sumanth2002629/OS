//Program Number:8
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: Signals


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void sigalrm_handler(int sig);
int main()
{
    struct itimerval t;
    t.it_interval.tv_sec = 3;
    t.it_interval.tv_usec = 0;

    t.it_value.tv_sec = 12;
    t.it_value.tv_usec = 0;

    //Catching SIGVTALRM signal
    signal(SIGVTALRM,sigalrm_handler);
    setitimer(ITIMER_VIRTUAL,&t,NULL);
    for(;;);
   
}

void sigalrm_handler(int sig)
{
    printf("SIGVTALRM has been received\n");
    //exit(0);
}