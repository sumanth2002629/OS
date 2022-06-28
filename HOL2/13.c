//Program Number:13
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: signals


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

void sigint_handler(int sig);
int main()
{
    int x = fork();
    if(x==0)
    {
        sleep(1);
        kill(getppid(),SIGSTOP);
        for(;;);
    }
    else
    {
        signal(SIGSTOP,sigint_handler);     //SIGSTOP cannot be caught
        for(;;);
    }
}

void sigint_handler(int sig)
{
    printf("SIGSTOP has been received\n");
    exit(0);
}