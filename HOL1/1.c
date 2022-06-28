//Program Number:1
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: Creating softlink,hardlink,fifo using system calls.

#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
//ln -s 
//ln
int main(){
    const char* target = "5.c";
    const char* linkpath = "cat";
    const char* pathname = "5.c";
    const char* linkname = "os";
    const char* fifopath = "5.c";
    
    int lns = symlink(target, linkpath);
    int ln = link(pathname, linkname);
    int fifo = mknod(fifopath, S_IFIFO, 0666);

    perror(fifopath);
    perror(linkname);
    perror(linkpath);

    printf("lns = %d\n", lns);
    printf("ln = %d\n", ln);
    printf("fifo = %d\n", fifo);
    return 0;
}