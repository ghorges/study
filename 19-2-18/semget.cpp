#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/sem.h>

using namespace std;

int main()
{
    int semid = semget(0x3333,1,IPC_CREAT | 0666);
    if(semid < 0)
    {
        perror("get err:");
        return -1;
    }

    
    std::cout << "Hello world" << std::endl;
    return 0;
}

