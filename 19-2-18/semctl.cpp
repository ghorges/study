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
union semun {
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO(Linux-specific) */
};
using namespace std;

int main()
{
    int semid = semget(0x3333,1,IPC_CREAT | 0666);
    if(semid < 0)
    {
        perror("get err:");
        return -1;
    }
    union semun sss;
    sss.val = 1;
    semctl(semid,0,SETVAL,sss);
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

