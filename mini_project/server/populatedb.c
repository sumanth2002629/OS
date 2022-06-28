#include "structures.h"
#include <unistd.h>
#include <fcntl.h>

void populate_user()
{
    int fd_user = open("user.dat",O_RDWR);

    struct User u[7];

    for(int i=0;i<7;i++)
    {
        u[i].u_id = i+1;
        u[i].password = 10000+i+1;
        u[i].is_admin = 0;
        u[i].acc_id = i+1;
    }

    u[0].is_admin = 1;u[0].acc_id=0;
    u[1].is_admin = 1;u[1].acc_id=0;

    u[5].acc_id = 6;
    u[6].acc_id = 6;

    write(fd_user,u,7*sizeof(struct User));

}

void populate_accounts()
{
     int fd_acc = open("acc.dat",O_RDWR);                                           
                                                                        
     struct Account a[6];                                       
                                
     for(int i=0; i<6; i++)
     {
         a[i].acc_id = i+1;
         a[i].balance = 0;
     }

     write(fd_acc,a,6*sizeof(struct User)); 

}

int main()
{
    populate_user();
    populate_accounts();
}