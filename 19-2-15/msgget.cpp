#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

using namespace std;
//就当文件描述符的用
//0666
int main()
{
    /*
    int a = msgget(0x1234,IPC_CREAT | IPC_EXCL);
    if(a < 0)
    {
        perror("geterr:");
    }
    */
    int a = msgget(0x1234,IPC_CREAT |0666);
    cout << a << endl;

    std::cout << "Hello world" << std::endl;
    return 0;
}

