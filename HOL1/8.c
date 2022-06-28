//Program Number:8
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This displays the contents of 4.c file in line by line fashion. As you press enter a new line will be printed.


#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    char buf[10000]={0};
    char c;
    int eof;
    int i = 0;
    int fd = open("4.c", O_RDONLY);
    int j=1;
    while(1)
    {
        j=read(fd,&c,1);
        if(j==0) break;
        if(c !=  '\n')
        {
            buf[i] = c;
            i++;
        }
        else
        {
            buf[i] = '\0';
            getchar();
            printf("%s",buf);
            i=0;
        }
    }
    buf[i] = '\0';
    getchar();
    printf("%s\n",buf);
    close(fd);
    
}