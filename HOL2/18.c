//Program Number:18
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: ls -l|grep ^d|wc -l

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
    int fd1[2],fd2[2];
    pipe(fd1);pipe(fd2);

    if(!fork())
    {
        dup2(fd1[1],1);
        close(fd2[0]);close(fd2[1]);
        close(fd1[0]);
        execlp("ls","ls","-l",(char *)0);
    }

    else
    {
        if(!fork())
        {
            dup2(fd1[0],0);dup2(fd2[1],1);
            close(fd1[1]);
            close(fd2[0]);
            execlp("grep","grep","^d",(char *)0);
        }
        else
        {
            sleep(2);
            dup2(fd2[0],0);
            close(fd2[1]);
            close(fd1[0]);close(fd1[1]);
            execlp("wc","wc","-l",(char *)0);
        }
    }
}