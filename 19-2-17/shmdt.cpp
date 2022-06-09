#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/shm.h>

using namespace std;
//先脱离，才能删除
struct teacher
{
    char c[1000];
};

int main()
{
    int t = shmget(0x2222,sizeof(teacher),IPC_CREAT | 0666);
    if(t < 0)
    {
        perror("err:");
        return -1;
    }

    teacher *p = (teacher*)shmat(t,NULL,0);
    //strcpy(p->c,"23142432423");
    sleep(10);    
    std::cout << "Hello world" << std::endl;
    
    
    cout << p->c << endl;
    shmdt(p);
    sleep(10);
    return 0;
}
