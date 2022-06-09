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
#include <pthread.h>
#include <string>

using namespace std;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int fd_get(int port)
{
    pthread_mutex_lock(&mutex);
    int sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
        perror("get sockerr:");
        return -1;                    
    }
    int yes = 1;
    if(setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes)) < 0)
    {
        perror("setsockopt addr err:");
        return -1;                            
    }
    if(setsockopt(sock,SOL_SOCKET,SO_REUSEPORT,&yes,sizeof(yes)) < 0)
    {
        perror("setsockopt port err:");
        return -1;
    }
    struct sockaddr_in addr;
    memset(&addr,0,sizeof(addr));
    addr.sin_family = AF_INET;

    short b = port;
    addr.sin_port = htons(b);
    addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    if(bind(sock,(struct sockaddr *)&addr,sizeof(addr)) < 0)
    {
        perror("bind err:");
        return -1;                                  
    }
    if(listen(sock,100) < 0)
    {
        perror("listen err:");
        return -1;                       
    }

    pthread_mutex_unlock(&mutex);
    return sock;
}
struct send_data
{
    char str[20];
    short port;
};

send_data da[2];
int dafd[2];
int m = 0;


void* handle_one(void*)
{
    int fd = fd_get(8888);
    if(fd < 0)
    {
        perror("create fd err:");
    }
    while(1)
    {
        struct sockaddr_in addr;
        socklen_t len  = sizeof(addr);
        bzero(&addr,sizeof(addr));
        cout << "zuse" << endl;
        int accfd = accept(fd,(struct sockaddr *)&addr,&len);
        cout << "port = " << addr.sin_port << endl;
        cout << "addr = " << inet_ntoa(addr.sin_addr) << endl;
        da[m].port = addr.sin_port;
        strcpy(da[m].str,inet_ntoa(addr.sin_addr));
        dafd[m] = fd;
        ++m;
    }
}

void* handle_two(void*)
{
    int fd = fd_get(8899);
    if(fd < 0)
    {   
        perror("create fd err:");
    }
    int flags = 1;
    while(1)
    {
        struct sockaddr_in addr;
        socklen_t len  = sizeof(addr);
        bzero(&addr,sizeof(addr));
        cout << "zese1" << endl;
        int accfd = accept(fd,(struct sockaddr *)&addr,&len);
        cout << "port = " << addr.sin_port << endl;
        cout << "addr = " << inet_ntoa(addr.sin_addr) << endl;
    
        while(m < 2)
        {
            sleep(1);
        }

        if (flags == 1) {
            int ret = send(dafd[0],(void*)(&(da[1])),sizeof(send_data),0);
            if(ret < 0)
            {
                perror("send err:");
            }
            flags = 0;
        }   

    
    }

}

int main(int argc,char **argv)
{
    if(argc != 3)
    {
        printf("格式:运行的文件 端口1 端口2\n");
        exit(0);
    }
    bzero(&da,sizeof(da));
    cout << atoi(argv[1]) << "   " << atoi(argv[2]) << endl;
    pthread_t t;
    pthread_create(&t,NULL,handle_one,NULL);
    pthread_create(&t,NULL,handle_two,NULL);
    int fd1 = fd_get(atoi(argv[1]));
    int fd2 = fd_get(atoi(argv[2]));
    if(fd1 <= 0 || fd2 <= 0)
    {
        return -1;
    }
    int flags = 0;
    while(1)
    {
        sleep(10);
    }
    return 0;
}
