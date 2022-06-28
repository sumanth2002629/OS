//Program Number:15
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: unnamed pipe


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int fd[2];
    pipe(fd);
    int x = fork();
    if(x!=0)
    {
        char buf[80] = {'H','e','l','l','o',' ','W','o','r','l','d','\0'};
        write(fd[1],buf,12);
    }
    else
    {
        char buf[80];
        read(fd[0],buf,12);
        printf("Data received by the child is %s\n",buf);
    }    
}