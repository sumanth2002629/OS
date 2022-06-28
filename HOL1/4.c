//Program Number:4
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: existing file is opened in ReadWrite mode and fd is printed. O_EXCL flag is also tried which prints error on creating the existing file.

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    char buf[100];
    int fd = open("4.c",O_RDWR|O_EXCL);
    perror("  ");
    printf("%d\n",fd);
}