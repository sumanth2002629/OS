//Program Number:21
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: fifo


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv []){
    int fd1 = open("myfifo1",O_RDWR);
    int fd2 = open("myfifo2",O_RDWR);
    const int msg_size = 1000;
    char msg_read[msg_size] ;
    char msg_write[msg_size];

    int size = read(fd1,msg_read,msg_size);
    printf("%s\n",msg_read);
    printf("enter message : ");
    scanf("%s",msg_write);
    write(fd2,msg_write,msg_size);
    
    return 0;
}
