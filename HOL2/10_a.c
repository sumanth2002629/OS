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
    sigaction(SIGSEGV, &sac,NULL);
    printf("Enter some number to generate SIGSEGV\n");
    scanf("%d",i);
}

void segfault_handler(int sig)
{
    printf("Segmentation fault has occured\n");
    exit(0);
}

