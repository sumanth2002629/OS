//Program Number:14
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: Given a file, detecting the file type.


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main()
{
    struct stat sb;
    char filetype[100];
    printf("Enter the path\n");
    scanf("%s",filetype);
    lstat(filetype,&sb);
    printf("File type: ");

           switch (sb.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
           }

}

