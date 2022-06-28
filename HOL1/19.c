//Program Number:19
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This prints the time taken to execute getpid()


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

   getpid();

   end = rdtsc();

   printf (" Difference is : %llu\n", end - start);
   printf("Time taken by getpid() in nano seconds:%lf \n",(end-start)/2.9);
   


}