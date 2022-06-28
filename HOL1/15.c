//Program Number:15
//Name:BTV Sumanth
//Register Number: IMT2020072
//Date: 25/02/22
//Description: This prints all env variables

#include <stdio.h>

int main(int argc, char **argv, char** envp)
{
    int i = 0;
    while(envp[i])
        printf("%s\n", envp[i++]);
}