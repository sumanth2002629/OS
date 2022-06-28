//Program Number:27
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: msg_queue

#include <sys/msg.h>
#include <stdio.h>

struct msgbuf {
    long mtype;
	char mtext [1];
};

int main()
{
    struct msgbuf mbuf;
    key_t key = ftok (".",'a');
    int msqid = msgget (key, 0);
    mbuf.mtype = 100;
    msgrcv (msqid, &mbuf, 1, 100, 0);
    printf("%c\n",mbuf.mtext[0]);

}