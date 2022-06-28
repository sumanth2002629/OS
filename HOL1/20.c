//Program Number:20
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: Prority of this process can be found using top. And it can be changed using renice command.

//renice -n -20 -p <pid>
//This changes the priority to -20

#include <stdio.h>
#include<unistd.h>
#include<sys/resource.h>
#include<sys/time.h>
int main()
{
        printf("Priority id before = %d\n",getpriority(PRIO_PROCESS,0));
        nice(10);
        printf("Priority id before = %d\n",getpriority(PRIO_PROCESS,0));
}