//Program Number:28
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: using msgctl


#include <sys/msg.h>
#include <stdio.h>

int main()
{
     struct msqid_ds msgq_ds;
     key_t key = ftok (".",'a');
     int msqid = msgget (key, IPC_CREAT|0666);
     msgctl(msqid, IPC_STAT, &msgq_ds);
     printf("Access permission before changing: %o\n",msgq_ds.msg_perm.mode);
     msgq_ds.msg_perm.mode = 0744;
     msgctl(msqid, IPC_SET, &msgq_ds);
     printf("Access permission after changing: %o\n",msgq_ds.msg_perm.mode);
}