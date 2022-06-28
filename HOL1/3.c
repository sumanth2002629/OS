//Program Number:3
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This prints the file descriptor of the created file.


#include <stdio.h>
#include <fcntl.h>
int main()
{
    int fd = creat("4.txt", O_CREAT|0744);
    printf("%d\n", fd);
}