#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/msg.h>
#include <sys/ipc.h>

using namespace std;
#define mmax 1024 * 4
struct mya
{
    long ttt;
    char c[mmax];
};

int main()
{
    int msgid = 0;
    msgid = msgget(0x1234,0666);
    if(msgid < 0)
    {
        perror("get err:");
        return 0;
    }
    mya buf;
    memset(&buf,0,sizeof(buf));
    int ret = msgrcv(msgid,&buf,mmax,1,IPC_NOWAIT);
    if(ret < 0)
    {
        perror("rcv err:");
        return -1;
    }
    cout << buf.c << endl;
    cout << "hello..." << endl;
    return 0;
}
