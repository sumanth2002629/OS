//Program Number:12
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: kill system call



#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>


int main()
{
    int x = fork();
    if(x==0)
    {
        printf("Parent process id before killing= %d\n",getppid());
        kill(getppid(),SIGKILL);
        sleep(1);
        printf("Parent process id after killing= %d\n",getppid());
        for(;;);
    }
    else
    {
        for(;;);
    }
}