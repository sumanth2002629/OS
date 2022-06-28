#include <sys/types.h>          
#include <sys/socket.h>
#include<netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "queries.h"

int loginHandler(int sd)
{
    int user_id,user_password,success=0,fail=-1;
    
    printf("Waiting for credentials\n");
    
    read(sd,&user_id,4);
 
    read(sd,&user_password,4);

    if(validate_login(user_id,user_password)!=0) 
    {
        write(sd,&fail,4);

        return -1;
    }

    write(sd,&success,4);

    return user_id;

}

int RequestHandler(int user_id,int sd)
{
    int amount,balance,ret,option,new_password;
    struct User *user = (struct User *)malloc(sizeof(struct User));
    char str[4];

    printf("user_id=%d\n",user_id);
    read(sd,&option,4);
    printf("client option=%d\n",option);
    
    switch(option)
    {
        case 1: 
            read(sd,&amount,4);
            ret=deposit(amount,user_id);
            write(sd,&ret,4);
            break;

        case 2: 
            read(sd,&amount,4);
            ret=withdraw(amount,user_id);
            write(sd,&ret,4);
            break;

        case 3: 
            balance = get_balance(user_id);
            write(sd,&balance,4);
            break;

        case 4: 
            read(sd,&new_password,4);
            ret=password_change(user_id,new_password);
            write(sd,&ret,4);
            break;

        case 5: 
            user = view_details(user_id);
            write(sd,user,sizeof(struct User));
            balance = get_balance(user_id);
            write(sd,&balance,4);
            break;
        case 6: 
            close(sd);
            break;
    }

}

int AdminHandler(int user_id,int sd)
{
    int amount,balance,ret,option,new_password,acc_id;
    struct User *user = (struct User *)malloc(sizeof(struct User));
    char str[4];

    printf("user_id=%d\n",user_id);
    read(sd,&option,4);
    printf("client option=%d\n",option);

    switch(option)
    {
        case 1: 
            read(sd,&balance,4);
            read(sd,&acc_id,4);
            ret=add_account(acc_id,balance);
            write(sd,&ret,4);
            break;

        case 2: 
            read(sd,&acc_id,4);
            read(sd,&balance,4);
            ret=modify_balance(acc_id,balance);
            write(sd,&ret,4);
            break;

        case 3: 
            read(sd,&acc_id,4);
            balance=get_acc_balance(acc_id);
            write(sd,&balance,4);
            break;

        case 4: 
            close(sd);
            break;
    }


}

int ServerHandler(int sd)
{
    int sd1=sd,option;
    int user_id = loginHandler(sd1);
    if(user_id==-1) return -1;

    if(user_id==1 || user_id==2)
    {
        printf("Admin logged in...\n");
        int x=AdminHandler(user_id,sd1);
    }
    
    else
    {
        printf("Normal user logged in...\n");
        int x=RequestHandler(user_id,sd1);
    } 

    

    
    return 0;
}

int main()
{
    struct sockaddr_in serv, cli;

    int sd = socket(AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons (5555);

    bind (sd, (struct sockaddr*)&serv, (sizeof (serv)));
    listen (sd, 5);

    int addrlen = sizeof(cli);
    int childpid;
     while(1)
     {
        int nsd = accept (sd, (struct sockaddr*)&cli, &addrlen);
        
        if((childpid=fork())==0)
        {
            close(sd);
            ServerHandler(nsd);
            return 1;
        }

        else 
            close(nsd);
     }

    return 0;

    
}