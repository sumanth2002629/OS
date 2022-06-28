//Program Number:17
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: ls -l|wc



#include <stdio.h>
#include <unistd.h>

int main(void)
{
    int fd[2];
    pipe(fd);
    
    if(!fork())
    {
        close(1);   
        close(fd[0]);
        dup(fd[1]);
        execlp("ls","-l",(char *)0);
    }
    else
    {
        close(0);
        close(fd[1]);
        dup(fd[0]);
        execlp("wc","wc",(char *)0);
    }
}