//Program Number:27
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: exploring given system calls to execute a executable program.



#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("Enter 1/2/3/4/5/6\n");
    int id;
    scanf("%d",&id);

    if(id==1)
    {
          printf("Using execl system call\n");
          execl("/bin/ls","ls","-Rl",(char*)0);
    }
    else if(id==2)
    {
        printf("Using execlp system call\n");
        execlp("ls","ls","-Rl",(char*)0);
    }
    else if(id==3)
    {
        printf("Using execle system call\n");
        execle("/bin/ls","ls", "-R","-l", NULL, NULL);
    }
    else if(id==4)
    {
        printf("Using execv system call\n");
        static char *argv[] = {"/bin/ls", "-Rl", NULL};
        execv(argv[0], argv);
    }
    else if(id==5)
    {
        printf("Using execvp system call\n");
         static char *argv[] = {"/bin/ls", "-Rl", NULL};
         execvp(argv[0], argv);
    }
}