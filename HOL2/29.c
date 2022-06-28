//Program Number:29
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: remove msgq

#include <sys/msg.h>
#include <stdio.h>

int main()
{
    key_t key = ftok (".",'a');
    int msqid = msgget (key, IPC_CREAT|0666);
    msgctl (msqid, IPC_RMID, NULL);
    return 0;
}