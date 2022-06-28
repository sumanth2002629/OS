//Program Number:25
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: msg queue statistics


#include <sys/msg.h>
#include <stdio.h>

int main()
{
     struct msqid_ds msgq_ds;
     key_t key = ftok (".",'a');
     int msqid = msgget (key, IPC_CREAT|0666);
     msgctl(msqid, IPC_STAT, &msgq_ds);

     printf("Access permission is: %o\n",msgq_ds.msg_perm.mode);
     printf("uid: %d\n",msgq_ds.msg_perm.uid);
     printf("gid: %d\n",msgq_ds.msg_perm.gid);
     printf("Last msg sent: %ld\n",msgq_ds.msg_stime);
     printf("Last msg rcvd: %ld\n",msgq_ds.msg_rtime);
     printf("Last msg change: %ld\n",msgq_ds.msg_ctime);
     printf("msq_q size in bytes: %ld\n",msgq_ds.msg_cbytes);
     printf("number of messages in the queue: %ld\n",msgq_ds.msg_qnum);
     printf("Max number of bytes allowed in the queue: %ld\n",msgq_ds.msg_qbytes);
     printf("msgsnd pid: %d\n",msgq_ds.msg_lspid);
     printf("msgrcv pid: %d\n",msgq_ds.msg_lrpid);

}