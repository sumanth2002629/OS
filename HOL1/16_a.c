//Program Number:16_a
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This implements mandatory fie locking(write lock). So when it is writing nobody else can read/write.Can be tested using two terminal tabs



#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    struct flock lock;
    int fd = open("file16_a.txt",O_RDWR);

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    
    printf("Before entering critical section\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("Critical Section\n");
    getchar();
    lock.l_type = F_UNLCK;
    printf("UNLOCK\n");
    fcntl(fd,F_SETLKW,&lock);
    close(fd);

}