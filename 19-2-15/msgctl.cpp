#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int msgid = msgget(0x1234,0666 | IPC_CREAT);
    if(msgid < 0)
    {
        perror("geterr:");
    }
    struct msqid_ds buf;
    memset(&buf,0,sizeof(buf));
    int a = msgctl(msgid,IPC_STAT,&buf);
    cout << buf.msg_ctime << endl;

    buf.msg_perm.mode = 0666;
    msgctl(msgid,IPC_SET,&buf);
    std::cout << "Hello world" << std::endl;
    return 0;
}

