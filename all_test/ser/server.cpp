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

using namespace std;

typedef struct send_file
{   
    int n;
    char pathname[100];
    char c[1000];
}send_file;

void handle(int t)
{
}

void *read_file(void *p)
{
    pthread_detach(pthread_self());


}
int main(int argc,char **argv)
{
    if(argc != 2)
    {
        printf("格式:运行的文件 端口\n");
        exit(0);
    }
    //signal(SIGINT,handle);
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

    int a = atoi(argv[1]);
    short b = a;
    printf("port = %d\n",b);
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

    while(1)
    {
        struct sockaddr_in addr;
        socklen_t len  = sizeof(addr);
        bzero(&addr,sizeof(addr));
        int accfd = accept(sock,(struct sockaddr *)&addr,&len);
        cout << "prot = " << addr.sin_port << endl;
        cout << "addr = " << inet_ntoa(addr.sin_addr) << endl;
        if (accfd < 0) {
            perror("accept err:");
            exit(0);
        }
    
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}
