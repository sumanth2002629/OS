//Program Number:21
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This prints parent and child process id

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int id = fork();
    if(!id)
    {
         printf("Child process id = %d\n",getpid());
    }
    else
    {
        printf("Parent process id = %d\n",getpid());
    }
}