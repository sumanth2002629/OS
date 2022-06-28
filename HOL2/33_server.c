//Program Number:33
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: server


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main(){
    char buf[256] = "You have reached the server";

    int sd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(9002);
    server.sin_addr.s_addr = INADDR_ANY;

    bind(sd, (struct sockaddr *)&server,sizeof(server));

    listen(sd,5);

    int nsd = accept(sd,NULL,NULL);
    write(nsd,buf,sizeof(buf));

    close(sd);
    return 0;
}