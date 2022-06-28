//Program Number:8
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
    //Catching SIGSEGV signal
    signal(SIGSEGV,segfault_handler);

    printf("Enter some number to generate SIGSEGV\n");
    scanf("%d",i);

    
}

void segfault_handler(int sig)
{
    printf("Segmentation fault has occured\n");
    exit(0);
}