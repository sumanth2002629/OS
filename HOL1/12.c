//Program Number:12
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: using fcntl to get file opening mode.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd = open("file11.txt",O_RDWR);
    int x= fcntl(fd,F_GETFL);
    printf("%d\n",x & O_ACCMODE);
}