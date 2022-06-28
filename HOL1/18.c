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
struct student
{
    int roll_no;
    int marks;
};

int main()
{
    struct flock lock;
    int fd = open("file18.txt",O_RDWR);
    struct student student1,student2,student3;
    student1.roll_no = 1;
    student1.marks = 80;
    student2.roll_no = 2;
    student2 .marks = 90;
    student3.roll_no = 3;
    student3.marks = 100;
    
    write(fd,&student1,sizeof(struct student));
    write(fd,&student2,sizeof(struct student));
    write(fd,&student3,sizeof(struct student));

    //implmenting the write lock before writing in the place of 2nd record.
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 8;
    lock.l_len = 8;
    lock.l_pid = getpid();
    
    printf("Before entering critical section\n");
    fcntl(fd,F_SETLKW,&lock);
    printf("Critical Section\n");
    getchar();


    //implementing read lock before reading the first record.
    lock.l_type = F_RDLCK;
    lock.l_start = 0;
    lock.l_len = 8;
   
    fcntl(fd,F_SETLKW,&lock);
     printf("Read LOCK\n");
    lock.l_type = F_UNLCK;
    lock.l_start = 8;
    lock.l_len = 8;
    fcntl(fd,F_SETLKW,&lock);
    
    getchar();
    close(fd);

}