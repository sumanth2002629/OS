#include<stdio.h>
//Program Number:2
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: Resource limits


#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>

int main(){

    struct rlimit r;

    getrlimit(RLIMIT_AS , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);

    getrlimit(RLIMIT_CORE , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);

    getrlimit(RLIMIT_CPU , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);

    getrlimit(RLIMIT_FSIZE , &r);
    printf("Soft Limit : %lu \nHard Limit : %lu\n\n",r.rlim_cur,r.rlim_max);


}