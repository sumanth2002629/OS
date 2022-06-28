//Program Number:17_b
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This increments ticket number in the ticket counter.


#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main()
{
    struct flock lock;
    int fd = open("ticket.txt",O_RDWR);

    
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    int ticket_no;
    lock.l_type = F_RDLCK;
    printf("Readlock\n");
    fcntl(fd,F_SETLKW,&lock);
    read(fd,&ticket_no,4);

    printf("%d\n",ticket_no);
    lseek(fd,-4,SEEK_CUR);
    ticket_no++;

    printf("Before write lock\n");
    lock.l_type = F_WRLCK;
    fcntl(fd,F_SETLKW,&lock);
    
    printf("After write lock\n");
    write(fd,&ticket_no,4);
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLKW,&lock);
    close(fd);
}    