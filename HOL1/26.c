//Program Number:26
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: Program to execute a executable program




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

  int option;
  printf("Enter 1/2 for 26a/26b:\n");
  scanf("%d",&option);
  if(option==1)
  {
    static char *argv[]={"test",NULL};
    execv(argv[0],argv);
  }  
  else if(option==2)
  {
      static char *argv[]={"test","1234",NULL};
      execv(argv[0],argv);
  }
}