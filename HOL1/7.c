//Program Number:7
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This copies contents of file 4.c to 100.c


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    char buf[1000000]={0};
    int fd = open("4.c", O_RDONLY);
    int fd1 = open("100.c",O_CREAT|O_RDWR,0744);
    read(fd,buf,sizeof(buf));
    write(fd1,buf,sizeof(buf));
    close(fd);
    close(fd1);
}