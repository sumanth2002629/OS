//Program Number:19
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: fifo using mknod


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    const char* buf = "pipe";
    mknod(buf, S_IFIFO|0, 0);
}
