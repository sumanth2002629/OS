//Program Number:23
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: FIFO limitations


#include <unistd.h>
#include <stdio.h>

int main()
{
    long PIPE_BUF, OPEN_MAX;
    PIPE_BUF = pathconf(".",_PC_PIPE_BUF);
    OPEN_MAX = sysconf(_SC_OPEN_MAX);
    printf("Pipe_buf = %ld\t OPEN_MAX = %ld\n",PIPE_BUF,OPEN_MAX);
}