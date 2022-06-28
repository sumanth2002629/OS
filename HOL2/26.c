//Program Number:26
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: msg queue

#include <sys/msg.h>
#include <stdio.h>

struct msgbuf {
    long mtype;
	char mtext [1];
};


int main()
{
    key_t key = ftok (".",'a');
    int msqid = msgget (key, IPC_CREAT|0666);
    struct msgbuf mbuf;
    mbuf.mtype = 100;
    mbuf.mtext[0] = 'a';
    msgsnd(msqid, &mbuf, sizeof(mbuf.mtext), 0);
    mbuf.mtype = 200;
    mbuf.mtext[0] = 'b';
    msgsnd(msqid, &mbuf, sizeof(mbuf.mtext), 0);
}