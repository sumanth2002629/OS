//Program Number:6,7
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: threads



#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *fun1(void *vargp)
{
    printf("printing hello world from thread1...\n");
    return NULL;
}

void *fun2(void *vargp)
{
    printf("printing hello world from thread2...\n");
    return NULL;
}

void *fun3(void *vargp)
{
    printf("printing hello world from thread3...\n");
    return NULL;
}

int main()
{
    pthread_t tid1,tid2,tid3;
    pthread_create(&tid1,NULL,fun1,NULL);
    //pthread_join(tid1,NULL); 
    pthread_create(&tid2,NULL,fun2,NULL);
    //pthread_join(tid2,NULL); 
    pthread_create(&tid3,NULL,fun3,NULL);
    //pthread_join(tid3,NULL); 
    sleep(2);

    printf("%ld %ld %ld\n",tid1,tid2,tid3);
    exit(0);
}