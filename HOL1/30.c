//Program Number:30
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: Deamon process




#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include <stdlib.h>

int main()
{
    if(!fork())
    {
        setsid();
        chdir("/");
        umask(0);
        while(1)
        {
            sleep(2);
            printf("Child pid:%d\n",getpid());
            printf("Deamon process is running\n");
        }

    }
    else
        exit(0);
}