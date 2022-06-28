#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(int argc,char* argv[])
{
    char zero = '\0';
    char next_line = '\n';
    char buf[100][1000],c;
    int fd = open(argv[1], O_RDWR);
    int total_duplicates = 0;
    int total_lines = 0;
    int i=0;
    int offset;
    while(1)
    {
        int j = read(fd,&c,1);
        if(j==0)
        {
            buf[total_lines][i] = '\0';
            total_lines++;
            break;
            //check with all lines outside the loop
        }
        if(c != '\n')
        {
            buf[total_lines][i++] =  c;
        }
        else
        {
            buf[total_lines][i] = '\0';
            total_lines++;
            i = 0;
        }
    }

    for(int i =0;i<total_lines;i++)
    {
        for(int j=i+1;j<total_lines;j++)
        {
            if(strcmp(buf[i],buf[j]) == 0)
            {
                int k = 0;
                while(buf[j][k]!='\0')
                {
                    buf[j][k] = '\0';
                    k++;
                }
                if(buf[i][0]!='\0')
                    total_duplicates++;
            }
        }
    }

    for(int i=0;i<(total_lines-total_duplicates);i++)
    {
        printf("%s\n",buf[i]);
    }
    printf("\n\n");
    printf("total Lines = %d & total duplicates = %d\n",total_lines,total_duplicates);
    
}