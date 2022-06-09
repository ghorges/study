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
/*int msgget(key_t key, int msgflg);*/
/*ipcrm msg id*/
int main01()
{
    /*
    //表示打开这个文件，这个文件必须要存在
    int msgid = msgget(0x1234,0666);
    if(msgid == -1)
    {
        if(errno == ENOENT)
        {
            cout << "自己检查，消息队列不存在" << endl;
            //perror("msgget err:");
            return -1;
        }
    }
    */
    
    //打开这个消息队列，若存在，就使用旧的，若不存在，就创建
    //注：O_CREAT不要使用，这个是为兼容设计的，有时候有问题
    int msgid = msgget(0x1234,0666 | IPC_CREAT);
    if(msgid == -1)
    {
        perror("msg err:");
        return -1;
    }
    cout << msgid << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}


int main02()
{
    //IPC_CREAT AND IPC_EXCL
    //如果存在，则会报错，害怕覆盖以前文件
    //单独用IPC_EXCL没有意义
    int msgid = msgget(0x1234,0666 | IPC_CREAT | IPC_EXCL);
    if(msgid == -1)
    {
        //EEXIST
        perror("msg err:");
        return -1;                            
    }
    cout << msgid << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

//IPC_PRIVATE
int main03()
{
    //只能供自己和家族的进程使用，不在没有血缘关系的进程间使用
    //当使用IPC_PRIVATE时候，后面的IPC_CREAT等都没有用
    //原理，每次创建的不一样，但是keys都是0000，没法拿到id嘛。。。
    //而且每一次创建的消息队列值不一样，所以只能给同家族的人
    int msgid = msgget(IPC_PRIVATE,0666);
    if(msgid == -1)
    {
        perror("msg err:");
        return -1;                    
    }
    cout << msgid << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

int main()
{
    int msgid = msgget(0x1234,0644|IPC_CREAT);
    if(msgid == -1) 
    {   
                perror("msg err:");
                return -1;                        
    }   
    msgid = msgget(0x1234,0444);

    if(msgid == -1)
    {
        //EACCES这个错误
        perror("msg err:");
        return -1;
    }
    cout << msgid << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}
