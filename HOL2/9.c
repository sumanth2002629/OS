//Program Number:9
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: signals


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    //ignoring SIGINT
    printf("Ignoring SIGINT\n");
    signal(SIGINT,SIG_IGN);
    sleep(5);

    printf("Default for SIGINT\n");
    signal(SIGINT,SIG_DFL);
    sleep(5);

    return 0;
}