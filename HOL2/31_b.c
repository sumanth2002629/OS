//Program Number:31
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: creating semaphore


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
    int semid = semget (key, 1, IPC_CREAT | 0644);
    arg.val = 5; 
    semctl (semid, 0, SETVAL, arg);
}