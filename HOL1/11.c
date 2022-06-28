//Program Number:11
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: Experimenting with dup,dup2,fcntl system calls.



#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd = open("file11.txt",O_RDWR);
    int fd1 = dup(fd);
    char buf[10] = {'H','E','L','L','O','H','O','W','A','R'};
    write(fd,buf,10);
    write(fd1,buf,10);
    close(fd);
    close(fd1);

    fd = open("file11.txt",O_RDWR);
    fd1 = dup2(fd,10);
    write(fd,buf,10);
    write(fd1,buf,10);
    close(fd);
    close(fd1);

    fd = open("file11.txt",O_RDWR);
    fd1 = fcntl(fd,F_DUPFD);
    write(fd,buf,10);
    write(fd1,buf,10);
    close(fd);
    close(fd1);

    return 0;
}