#include "queries.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>


int deposit(int amount,int user_id)
{
    int fd_user = open("user.dat",O_RDWR);struct flock lock;
    int fd_acc = open("acc.dat",O_RDWR);int x;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    struct User *user = (struct User *)malloc(sizeof(struct User));

    lseek(fd_user,(user_id-1)*sizeof(struct User),SEEK_SET);
    fcntl(fd_user,F_SETLKW,&lock);
    
    read(fd_user,user,sizeof(struct User));

   
    lock.l_type = F_UNLCK;
    fcntl(fd_user,F_SETLKW,&lock);

    int acc_id = user->acc_id;

    struct Account *account = (struct Account *)malloc(sizeof(struct Account));
    lseek(fd_acc,(acc_id-1)*sizeof(struct Account),SEEK_SET);

    lock.l_type = F_RDLCK;
    fcntl(fd_acc,F_SETLKW,&lock);

    read(fd_acc,account,sizeof(struct Account));

    lseek(fd_acc,(acc_id-1)*sizeof(struct Account),SEEK_SET);

    lock.l_type = F_UNLCK;
    fcntl(fd_user,F_SETLKW,&lock);

    lock.l_type = F_WRLCK;
    fcntl(fd_acc,F_SETLKW,&lock);

    account->balance += amount;
    write(fd_acc,account,sizeof(struct Account));

    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd_acc,F_SETLKW,&lock);


    return 0;
}

int get_balance(int user_id)
{
    int fd_user = open("user.dat",O_RDWR);struct flock lock;
    int fd_acc = open("acc.dat",O_RDWR);

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    struct User *user = (struct User *)malloc(sizeof(struct User));

    lseek(fd_user,(user_id-1)*sizeof(struct User),SEEK_SET);
    fcntl(fd_user,F_SETLKW,&lock);
    
    read(fd_user,user,sizeof(struct User));

    lock.l_type = F_UNLCK;
    fcntl(fd_user,F_SETLKW,&lock);

    int acc_id = user->acc_id;

    struct Account *account = (struct Account *)malloc(sizeof(struct Account));
    lseek(fd_acc,(acc_id-1)*sizeof(struct Account),SEEK_SET);

    lock.l_type = F_RDLCK;
    fcntl(fd_acc,F_SETLKW,&lock);

    read(fd_acc,account,sizeof(struct Account));

    lock.l_type = F_UNLCK;
    fcntl(fd_acc,F_SETLKW,&lock);


    return account->balance;
}

int validate_login(int user_id,int password)
{
    int fd = open("user.dat",O_RDWR);struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    struct User *user = (struct User *)malloc(sizeof(struct User));

    fcntl(fd,F_SETLKW,&lock);

    for(int i=0;i<7;i++)
    {
        struct User *user = malloc(sizeof(struct User));
        read(fd,user,sizeof(struct User));
        if(user->u_id==user_id && user->password==password) return 0;
    }

    lock.l_type = F_UNLCK;
    lock.l_start = 0;
    lock.l_len = 0;
    fcntl(fd,F_SETLKW,&lock);

    printf("Wrong credentials\n");
    return -1;
}

int withdraw(int amount,int user_id)
{

    if(amount>get_balance(user_id)) return -1;

    int fd_user = open("user.dat",O_RDWR);struct flock lock;
    int fd_acc = open("acc.dat",O_RDWR);

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    struct User *user = (struct User *)malloc(sizeof(struct User));

    lseek(fd_user,(user_id-1)*sizeof(struct User),SEEK_SET);
    fcntl(fd_user,F_SETLKW,&lock);
    
    read(fd_user,user,sizeof(struct User));

    printf("userid=%d\n",user->u_id);
    printf("user_accid=%d\n",user->acc_id);

    lock.l_type = F_UNLCK;
    fcntl(fd_user,F_SETLKW,&lock);

    int acc_id = user->acc_id;

    struct Account *account = (struct Account *)malloc(sizeof(struct Account));
    lseek(fd_acc,(acc_id-1)*sizeof(struct Account),SEEK_SET);

    lock.l_type = F_RDLCK;
    fcntl(fd_acc,F_SETLKW,&lock);

    read(fd_acc,account,sizeof(struct Account));
    printf("acc_accid=%d\n",account->acc_id);

    lseek(fd_acc,(acc_id-1)*sizeof(struct Account),SEEK_SET);

    lock.l_type = F_WRLCK;
    fcntl(fd_acc,F_SETLKW,&lock);

    account->balance -= amount;
    write(fd_acc,account,sizeof(struct Account));

    lock.l_type = F_UNLCK;
    fcntl(fd_acc,F_SETLKW,&lock);


    return 0;
}

int password_change(int user_id,int new_password)
{
    int fd_user = open("user.dat",O_RDWR);struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    struct User *user = (struct User *)malloc(sizeof(struct User));

    lseek(fd_user,(user_id-1)*sizeof(struct User),SEEK_SET);
    fcntl(fd_user,F_SETLKW,&lock);
    
    read(fd_user,user,sizeof(struct User));

    user->password = new_password;

    lock.l_type = F_WRLCK;
    lseek(fd_user,(user_id-1)*sizeof(struct User),SEEK_SET);
    fcntl(fd_user,F_SETLKW,&lock);

    write(fd_user,user,sizeof(struct User));

    lock.l_type = F_UNLCK;
    fcntl(fd_user,F_SETLKW,&lock);

    return 0;
}

struct User* view_details(int user_id)
{
    int fd_user = open("user.dat",O_RDWR);struct flock lock;
    int fd_acc = open("acc.dat",O_RDWR);
    int balance;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    struct User *user = (struct User *)malloc(sizeof(struct User));

    lseek(fd_user,(user_id-1)*sizeof(struct User),SEEK_SET);
    fcntl(fd_user,F_SETLKW,&lock);
    
    read(fd_user,user,sizeof(struct User));
    lock.l_type = F_UNLCK;
    fcntl(fd_user,F_SETLKW,&lock);

    return user;
}

int add_account(int acc_id,int balance)
{
    int fd_acc = open("acc.dat",O_RDWR);struct flock lock;
    lseek(fd_acc,0,SEEK_END);

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    struct Account *acc = (struct Account *)malloc(sizeof(struct Account));
    acc->acc_id = acc_id;
    acc->balance = balance;

    fcntl(fd_acc,F_SETLKW,&lock);

    write(fd_acc,acc,sizeof(struct Account));

    lock.l_type = F_UNLCK;
    fcntl(fd_acc,F_SETLKW,&lock);

    return 0;

}

int get_acc_balance(int acc_id)
{
    int fd_acc = open("acc.dat",O_RDWR);struct flock lock;
    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    fcntl(fd_acc,F_SETLKW,&lock);

    struct Account *acc = (struct Account *)malloc(sizeof(struct Account));
    while(1)
    {
        if(read(fd_acc,acc,sizeof(struct Account))==0) break;

        if(acc->acc_id == acc_id){
            lock.l_type = F_UNLCK;
            fcntl(fd_acc,F_SETLKW,&lock);
            return acc->balance;
        } 
    }

    lock.l_type = F_UNLCK;
    fcntl(fd_acc,F_SETLKW,&lock);
    return -1;
}

int modify_balance(int acc_id,int balance)
{
    int fd_acc = open("acc.dat",O_RDWR);struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    fcntl(fd_acc,F_SETLKW,&lock);

    struct Account *acc = (struct Account *)malloc(sizeof(struct Account));
    while(1)
    {
        if(read(fd_acc,acc,sizeof(struct Account))==0) break;

        if(acc->acc_id == acc_id)
        {
            acc->balance = balance;
            lseek(fd_acc,-1*sizeof(struct Account),SEEK_CUR);
            write(fd_acc,acc,sizeof(struct Account));

            lock.l_type = F_UNLCK;
            fcntl(fd_acc,F_SETLKW,&lock);
            return 0;
        } 

    }
    lock.l_type = F_UNLCK;
    fcntl(fd_acc,F_SETLKW,&lock);
    return -1;
}