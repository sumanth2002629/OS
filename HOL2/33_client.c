//Program Number:33
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 10/05/2022
//Description: client


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>



int main(){

    //creating a socket for the client
    int sd = socket(AF_UNIX,SOCK_STREAM,0);

    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = INADDR_ANY;

    int conn_status = connect(sd,(struct sockaddr*)&server,sizeof(server));

    if(conn_status==-1)
    {
        printf("Connection Error\n");
    }
    else printf("Connected successfully\n");

    char buf[100];
    read(sd,buf,sizeof(buf));

    printf("The server sent data = %s\n",buf);


    close(sd);

    return 0;
}
