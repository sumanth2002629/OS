//Program Number:6
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This takes input from terminal and prints on the terminal only using read/write system calls


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    char buf[1000]={0};
    read(0,buf,sizeof(buf));
    write(1,buf,sizeof(buf));
}