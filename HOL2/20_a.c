//Program Number:20
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
    int fd = open("myfifo",O_RDONLY);
    char msg[100] ;
    int size = read(fd,msg,100);
    printf("%s\n",msg);
    return 0;
}
