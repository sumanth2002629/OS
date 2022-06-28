//Program Number:16
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: unnamed pipe, two way communication.

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
        char buf[80] = {'H','e','l','l','o',' ','C','h','i','l','d','\0'};
        write(fd[1],buf,12);
        sleep(1);
        read(fd[0],buf,12);
        printf("Data received by the parent is %s\n",buf);

    }
    else
    {
        char buf[80];
        char buf1[80] = {'H','e','l','l','o',' ','P','a','r','e','n','t','\0'};
        read(fd[0],buf,12);
        printf("Data received by the child is %s\n",buf);
        write(fd[1],buf1,13);
    }    
}