//Program Number:24
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This creates a child process which is orphan for 50sec..



#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fork_ret = fork();
    if(fork_ret==0) 
    {
        sleep(50);
        printf("Child");
    }
    else
    {
        printf("Parent");
    }
}