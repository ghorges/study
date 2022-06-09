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
struct my_msgbuf {
    long mtype;       // message type, must be > 0 
    char mtext[mmax];    // message data                                             
};

int main(int argc,char **argv)
{
    int msgid = 0;
    msgid = msgget(0x1234,0666);
    if(msgid < 0)
    {
        perror("get err:");
        return -1;
    }
    my_msgbuf buf;
    memset(&buf,0,sizeof(buf));
    buf.mtype = 1;
    strcpy(buf.mtext,"233333333333333333");
    
    // int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
    if(msgsnd(msgid,&buf,10,IPC_NOWAIT) < 0)
    {
        perror("snd err:");
        return -1;
    }

    std::cout << "Hello world" << std::endl;
    return 0;
}

