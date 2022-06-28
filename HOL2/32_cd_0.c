//Program Number:32
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: semaphore


#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/msg.h>

union semun {
  int val;      // value for SETVAL 
  struct semid_ds *buf;  // buffer for IPC_STAT, IPC_SET
  unsigned short int *array;  // array for GETALL, SETALL   
 };

int main()
{
    union semun arg;
    key_t key = ftok (".",'b');
    int semid = semget (key, 2, IPC_CREAT | 0644);
    static ushort val[2]={1,1};
    unsigned short int val1[2];

    arg.array = val; 

    semctl (semid, 0, SETALL, val);

    semctl (semid,0,GETALL,val1);
    printf("%d %d\n",val1[0],val1[1]);
}