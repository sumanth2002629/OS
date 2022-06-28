//Program Number:30
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: shared memory


#include <sys/ipc.h>
#include <unistd.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    key_t key = ftok (".",'b');
    int shmid = shmget(key, 100, IPC_CREAT|0744);
    char *data;

    data = (char*)shmat(shmid,NULL,0);  // flag as 0 = read+write

    printf("Enter Text : \n");
    scanf("%[^\n]",data);
    

    data = (char*)shmat(shmid,NULL,SHM_RDONLY);  //attaching shm in readonly mode.
    printf("Enter Text : \n");
    scanf("%[^\n]",data);

    printf ("SHM contents : %s \n", data);

    shmdt (data);  //detaching shm

    shmctl (shmid, IPC_RMID, NULL); //removing shm

}