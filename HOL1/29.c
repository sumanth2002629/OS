//Program Number:29
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This will print existing scheduling policy and changes it to FIFO/RR and prints again.

#include <sched.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int x=sched_getscheduler(getpid());
    printf("Scheduling policy = %d\n",x);
    
    struct sched_param sp = { .sched_priority = 50 };
    int ret;

    ret = sched_setscheduler(0, SCHED_FIFO, &sp);  //changing policy to FIFO
    if (ret == -1) {
    perror("sched_setscheduler");
    return 1;
    }

    x=sched_getscheduler(getpid());
    printf("Scheduling policy before = %d\n",x);

    //sp = { .sched_priority = 50 };

    ret = sched_setscheduler(0, SCHED_RR, &sp);    //Changing policy to RR
    if (ret == -1) {
    perror("sched_setscheduler");
    return 1;
    }

    x=sched_getscheduler(getpid());
    printf("Scheduling policy after = %d\n",x);
}