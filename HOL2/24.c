//Program Number:24
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: msg queue


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok (".",'a');
    printf("Key is %d\n",key);
    int msqid = msgget (key, IPC_CREAT|0666);
    printf("message queue id is %d\n",msqid);
}
