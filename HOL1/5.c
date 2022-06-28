//Program Number:5
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This creates 5 files. So fd table has 8 entries.(0 to 7)

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd1 = creat("4.txt", O_CREAT|0744);
    int fd2 = creat("5.txt", O_CREAT|0744);
    int fd3 = creat("6.txt", O_CREAT|0744);
    int fd4 = creat("7.txt", O_CREAT|0744);
    int fd5 = creat("8.txt", O_CREAT|0744);
    printf("%d %d %d %d %d\n",fd1,fd2,fd3,fd4,fd5);
 
    while(1)
    {
        ;
    }
}