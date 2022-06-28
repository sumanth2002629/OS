//Program Number:10
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: Empty space between the data is detected.


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
    int fd = open("file10.txt",O_RDWR);
    char buf[10] = {'H','E','L','L','O','H','O','W','A','R'};
    write(fd,buf,10);
    int x = lseek(fd,10,SEEK_CUR);
    printf("lseek returns %d\n",x);
    write(fd,buf,10);
    close(fd);

    system("od -c file10.txt");
}