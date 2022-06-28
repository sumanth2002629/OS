//Program Number:19
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: fifo using mkfifo



#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    const char * name = "pipe";
    mkfifo(name,0);
}