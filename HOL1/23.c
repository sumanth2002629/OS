//Program Number:23
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This creates a child zombie process for 30 seconds.


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int fork_ret = fork();
    if(fork_ret==0) 
    {
        printf("I am Child");  
    }
    else
    {
        sleep(30);
        printf("Parent");
    }
}