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
int sem_p(int semid)
{
    struct sembuf buf = {0,-1,0};
    int ret = 0;
    ret = semop(semid,&buf,1);
    return ret;
}
int sem_v(int semid)
{
    struct sembuf buf = {0,1,0};
    int ret = 0;
    ret = semop(semid,&buf,1);
    return ret;
}
int main()
{
    int semid = semget(0x3333,1,IPC_CREAT | 0666);
    if(semid < 0)
    {
        perror("get err:");
        return -1;
    }
    union semun sss;
    sss.val = 0;
    semctl(semid,0,SETVAL,sss);
    
    sem_p(semid);
    sem_v(semid);
    std::cout << "Hello world" << std::endl;
    return 0;
}

