//Program Number:25
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: Parent waits for particular child with given id in waitpid system call.

#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int i,j,k;
    if(!(i=fork()))
        sleep(1);
    else
        if(!(j=fork()))
            sleep(5);
        else
            if(!(k=fork()))
                sleep(10);
            else
                waitpid(i,NULL,0);  //i/j/k can be given based on for which process should the parent wait.

}