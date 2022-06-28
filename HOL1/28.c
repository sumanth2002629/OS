//Program Number:28
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: Prints max and min priority of real time processes.

#include <sched.h>
#include <stdio.h>
int main()
{
    printf("max real time priority(FIFO) = %d\n",sched_get_priority_max(SCHED_FIFO));
    printf("min real time priority(FIFO) = %d\n",sched_get_priority_min(SCHED_FIFO));
    printf("max real time priority(RR) = %d\n",sched_get_priority_max(SCHED_RR));
    printf("min real time priority(RR) = %d\n",sched_get_priority_min(SCHED_RR));
    printf("max real time priority = %d\n",sched_get_priority_max(SCHED_OTHER));
    printf("min real time priority = %d\n",sched_get_priority_min(SCHED_OTHER));

}

