//Program Number:1
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: ITIMER_VIRTUAL


#include <stdio.h>
#include <sys/time.h>


int main(){
    
    struct itimerval value;
    // Time until next expiration
    value.it_value.tv_sec = 20;
    value.it_value.tv_usec = 0;

    // Interval for periodic timer
    value.it_interval.tv_sec = 10;
    value.it_interval.tv_usec = 10;

    setitimer(ITIMER_VIRTUAL,&value,NULL);

    while(1);

}