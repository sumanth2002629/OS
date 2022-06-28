#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
	int fd,fd1;
	char buf[80];

	fd = open("file",  O_RDWR);
	write(fd,"HELLO\n",7);
	close(fd);
	fd = open("file",O_RDWR);
	read(fd,buf,sizeof(buf));
	printf("%s\n",buf);
	close(fd);
}
