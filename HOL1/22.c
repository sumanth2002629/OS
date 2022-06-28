//Program Number:22
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: parent and child both writes to the file.


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
     int fd = open("22.txt",O_CREAT|O_RDWR,0744);  
     int x = fork();
     if(x==0)
     {
         write(fd,"Child..\n",9);
     }  
     else
     {
          write(fd,"Parent..\n",10);
     }
}