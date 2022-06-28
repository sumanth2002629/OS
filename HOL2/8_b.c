//Program Number:8
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: Signals


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void sigint_handler(int sig);
int main()
{
    int i;
    //Catching SIGINT signal
    signal(SIGINT,sigint_handler);
    printf("Press Ctrl C to generate SIGINT\n");
    for(;;);
    

    
}

void sigint_handler(int sig)
{
    printf("SIGINT has been received\n");
    exit(0);
}