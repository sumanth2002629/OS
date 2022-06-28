//Program Number:17_a
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This stores the ticket number and initialises it to 1

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd1 = open("ticket.txt",O_CREAT|O_RDWR,0744);
    int x=1;
    write(fd1,&x,sizeof(x));
    close(fd1);
}