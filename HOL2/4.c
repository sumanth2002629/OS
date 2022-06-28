//Program Number:4
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: timestamp counter


#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
# include <sys/time.h>

unsigned long long rdtsc ( )  
{
     unsigned long long dst;
     __asm__ __volatile__("rdtsc":"=A"(dst));
     return dst;  
 }
int main(){

    long long int start, end;

    start = rdtsc();

    for(int i=0;i<100;i++)
    {
        getpid();
    }

    end = rdtsc();

    printf (" Difference is : %llu\n", end - start);
    printf("Time taken by getpid() in nano seconds:%lf \n",(end-start)/2.9);
   


}