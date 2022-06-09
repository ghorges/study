#include <iostream>
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
#include <sys/socket.h>
#include <arpa/inet.h>
#include <signal.h>

using namespace std;

int con = 0;
union semun{
    int val;
    struct semid_ds *buf;
    unsigned short *arrays;
    struct seminfo *_buf;
};

int sem_init()
{
    int key = ftok(".",1);
    int semid = semget(key,1,0666 | IPC_CREAT);
    if(semid < 0)
    {
        perror("semid err:");
        return -1;
    }
    semun su;
    su.val = 1;
    if(semctl(semid,0,SETVAL,su) < 0)
    {
        perror("semctl err:");
        return -1;
    }
    return semid;
}
int *shm_init()
{
    int key = ftok(".",1);
    int shmid = shmget(key,100,0666 | IPC_CREAT);
    if(shmid < 0)
    {
        perror("shmget err:");
        return NULL;
    }
    int *p = (int *)shmat(shmid,0,0);
    return p;
}
void sem_p(int semid)
{
    struct sembuf buf = {0,-1,SEM_UNDO};
    if(semop(semid,&buf,1) < 0)
    {
        perror("semop err:");
        return;
    }
}
void sem_v(int semid)
{
    struct sembuf buf = {0,1,SEM_UNDO};
    if(semop(semid,&buf,1) < 0)
    {
        perror("semop err:");
        return;
    }
}
void handle(int t)
{
    int *c = shm_init();
    cout << c[0] << endl;
}
int main()
{
    signal(SIGINT,handle);
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
        perror("get sockerr:");
        return -1;
    }
    int yes = 1;
    if(setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes)) < 0)
    {
        perror("setsockopt err:");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8888);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(bind(sock,(struct sockaddr *)&addr,sizeof(addr)) < 0)
    {
        perror("bind err:");
        return -1;
    }
    if(listen(sock,20) < 0)
    {
        perror("listen err:");
        return -1;
    }

    int semid = sem_init();
    int *c = shm_init();
    c[0] = 0;

    while(1)
    {
        struct sockaddr_in addr;
        socklen_t len  = sizeof(addr);
        int accfd = accept(sock,(struct sockaddr *)&addr,&len);
        int pid = fork();
        if(pid > 0)
        {
            continue;
        }
        if(pid == 0)
        {
            while(1)
            {
            char buf[100] = { 0 };
            memset(buf,0,sizeof(buf));
            int t = recv(accfd,buf,sizeof(buf),0);
            if(t == 0)
            {
                cout << "连接断开" << endl;
                return 0;
            }
            if(t > 0)
            {
                cout << buf << endl;
                sem_p(semid);
                c[0]++;
                sem_v(semid);
                cout << c[0] << endl;
            }
            if(t < 0)
            {
                cout << "recv err" << endl;
                return -1;
            }
            }
        }
        if(pid < 0)
        {
            perror("fork err:");
            return -1;
        }
    }


    std::cout << "Hello world" << std::endl;
    return 0;
}

