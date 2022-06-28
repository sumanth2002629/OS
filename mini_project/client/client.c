#include <stdio.h>
#include <sys/types.h>          
#include <sys/socket.h>
#include<netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include "../server/structures.h"

int loginHandler(int sd)
{
    int user_id,user_password,logged_in;
    printf("Enter user_id\n");
    scanf("%d",&user_id);
    printf("Enter user_password\n");
    scanf("%d",&user_password);
    write(sd,&user_id,4);
    write(sd,&user_password,4);

    read(sd,&logged_in,sizeof(logged_in));

    if(logged_in!=0) return -1;

    return user_id;
}

int Usermenu(int user_id,int sd)
{
    int option,success,amount,balance,new_password;
    struct User *user = (struct User *)malloc(sizeof(struct User));
    printf("Select one of the options you want to perform\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Balance Enquiry\n");
    printf("4. Password change\n");
    printf("5. View details\n");
    printf("6. exit\n");
    scanf("%d",&option);
    int x =option;
    write(sd,&option,4);

    switch(option)
    {
        case 1:
            printf("Enter the amount you want to deposit...\n");
            scanf("%d",&amount);
            write(sd,&amount,4);
            read(sd,&success,4);
            if(success==0) printf("Amount deposited successfully...\n");
            break;
        case 2:
            printf("Enter the amount you want to withdraw...\n");
            scanf("%d",&amount);
            write(sd,&amount,4);
            read(sd,&success,4);
            if(success==0) printf("Amount withdrawn successfully...\n");
            else printf("You don't have enough balance to withdraw\n");
            break;
        case 3:
            read(sd,&balance,4);
            printf("Your current balance is %d ...\n",balance);
            break;
        case 4:
            printf("Enter new password...\n");
            scanf("%d",&new_password);

            write(sd,&new_password,4);
            read(sd,&success,4);
            if(success==0) printf("Password changed successfully...");
            break;

        case 5:
            read(sd,user,sizeof(struct User));
            printf("==== Your Details ====\n");
            printf("User_id = %d\n",user->u_id);
            printf("password = %d\n",user->password);
            if(user->is_admin==1)
                printf("Admin status: Admin\n");
            else if(user->is_admin==0)
                printf("Admin status: Not an admin\n");
            printf("Account id = %d\n",user->acc_id);
            read(sd,&balance,4);
            printf("Account Balance = %d\n",balance);
            break;

        case 6:
            close(sd);
            break;
    }

}

int Adminmenu(int user_id,int sd)
{
    int option,success,amount,balance,new_password,acc_id;
    struct User *user = (struct User *)malloc(sizeof(struct User));
    printf("Select one of the options you want to perform\n");
    printf("1. Add account\n");
    printf("2. Modify account\n");
    printf("3. Search Account\n");
    printf("4. exit\n");
    scanf("%d",&option);
    write(sd,&option,4);

    switch(option)
    {
        case 1:
            printf("Enter the new account balance and account id which is to be added\n");
            scanf("%d%d",&balance,&acc_id);

            write(sd,&balance,4);
            write(sd,&acc_id,4);
            read(sd,&success,4);
            if(success==0) printf("Account added successfully\n");
            break;
        case 2:
            printf("Enter the account id and new balance\n");
            scanf("%d%d",&acc_id,&balance);
            write(sd,&acc_id,4);
            write(sd,&balance,4);
            read(sd,&success,4);
            if(success==0) printf("Account balance modified successfully\n");
            break;
        case 3:
            printf("Enter account id of which you want to get balance...\n");
            scanf("%d",&acc_id);

            write(sd,&acc_id,4);
            read(sd,&balance,4);
            printf("Your balance is %d\n",balance);
            break;

        case 4:
            close(sd);
            break;
    }

    
    return 0;
}

int ClientHandler(int sd)
{
    int user_id = loginHandler(sd);
    if(user_id==-1) return -1;
    
    if(user_id==1 || user_id==2) 
        Adminmenu(user_id,sd);
    else 
        Usermenu(user_id,sd);


    
}

int main()
{
    struct sockaddr_in serv;
    int sd = socket (AF_INET, SOCK_STREAM, 0);

    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons (5555);

    connect (sd, (struct sockaddr*)&serv, sizeof(serv));

    int ret = ClientHandler(sd);
    if(ret==-1) {
        printf("Wrong Credentials!!\n");
        close(sd);
    }

    return 0;
}