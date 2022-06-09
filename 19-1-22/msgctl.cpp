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
/*
struct ipc_perm {
key_t          __key;       / Key supplied to msgget(2) /
uid_t          uid;         / Effective UID of owner /
gid_t          gid;         / Effective GID of owner /
uid_t          cuid;        / Effective UID of creator /
gid_t          cgid;        / Effective GID of creator /
unsigned short mode;        / Permissions /
unsigned short __seq;       / Sequence number                                                                         
};
*/
int main()
{
    int msgid = 0;
    msgid = msgget(0x1234,0666);
    if(msgid < 0)
    {
        perror("msgget err:");
        return -1;
    }
    struct msqid_ds buf;
    memset(&buf,0,sizeof(buf));
    int ret = msgctl(msgid,IPC_STAT,&buf);
    if(ret == -1){
        perror("ctl err:");
        return -1;
    }
    //int msgctl(int msqid, int cmd, struct msqid_ds *buf);
    printf("%o",buf.msg_perm.mode);
    std::cout << "Hello world" << std::endl;
    return 0;
}

