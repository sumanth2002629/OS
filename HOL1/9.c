//Program Number:9
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: All the info about this file was printed.

#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/sysmacros.h>
int main()
{
    struct stat sb;
    lstat("9.c",&sb);
    printf("inode number = %ld\n", (long)sb.st_ino);
    printf("number of hardlinks = %ld\n", (long)sb.st_nlink);
    printf("uid = %ld\n", (long)sb.st_uid);
    printf("gid = %ld\n", (long)sb.st_gid);
    printf("filesize = %ld\n", (long)sb.st_size);
    printf("blocksize = %ld\n", (long)sb.st_blksize);
    printf("number of blocks = %ld\n", (long)sb.st_blocks);
    printf("time of last access: %s", ctime(&sb.st_atime));
    printf("time of last modification: %s", ctime(&sb.st_mtime));
    printf("time of last change: %s", ctime(&sb.st_ctime));
    return 0;
}
