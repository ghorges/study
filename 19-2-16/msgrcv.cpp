#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct aa
{
    long type;
    char c[1000];
};
int main()
{
    int msgid = msgget(0x1234,0666 | IPC_CREAT);
    if(msgid < 0)
    {
        perror("get err:");
        return -1;
    }
    
    aa buf;
    memset(&buf,0,sizeof(buf));
    //int t = msgrcv(msgid,&buf,10,1,0);
    int t = msgrcv(msgid,&buf,10,1,IPC_NOWAIT);
    if(t < 0)
    {
        perror("rcv err:");
        return -1;
    }
    cout << buf.c << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

