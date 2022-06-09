#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct msgbuff{
    long type;
    char c[100];
};


int main()
{
    int msget = msgget(0x1234,0666 | IPC_CREAT);
    if(msget < 0)
    {
        perror("err:");
    }
    msgbuff buf1;
    buf1.type = 1;
    strcpy(buf1.c,"weq8fgwg");

    msgsnd(msget,&buf1,10,0);
    std::cout << "Hello world" << std::endl;
    return 0;
}

