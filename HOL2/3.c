//Program Number:3
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: Resource limits



#include<stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main(){

    struct rlimit r;

    getrlimit(RLIMIT_FSIZE , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);

    r.rlim_cur = 1;
    r.rlim_max = 3;

    setrlimit(RLIMIT_FSIZE, &r);
    
    getrlimit(RLIMIT_FSIZE , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);
}