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

int fd_get(int port)
{
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

    return sock;
}


int cli_fd(short cli_port,short ser_port,char* address)
{
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd == -1) 
    {   
        perror("socket err:");
        return -1; 
    }

    int yes = 1;
    if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes)) < 0)
    {   
        perror("setsockopt err:");
        return -1;
    }

    struct sockaddr_in con_addr;
    memset(&con_addr,0,sizeof(con_addr));
    con_addr.sin_family = AF_INET;
    con_addr.sin_port = htons(ser_port);
    con_addr.sin_addr.s_addr = inet_addr(address);

    struct sockaddr_in bind_addr;
    memset(&bind_addr,0,sizeof(bind_addr));
    bind_addr.sin_family = AF_INET;
    bind_addr.sin_port = htons(cli_port);
    bind_addr.sin_addr.s_addr = inet_addr("0.0.0.0");
    if(bind(fd,(struct sockaddr *)&bind_addr,sizeof(bind_addr)) < 0)
    {   
        perror("bind err:");
        return -1; 
    }

    cout << "connect wait" << endl;
    
    if(connect(fd,(struct sockaddr *)&con_addr,sizeof(con_addr)) < 0)
    {
        perror("conn err:");
        return -1;                                    
    }
    cout << "connect ok" << endl;
    return fd;
}



int main(int argc,char **argv)
{
    if(argc != 3)
    {
        printf("格式:运行的文件 端口1 端口2\n");
        exit(0);
    }
    cout << atoi(argv[1]) << "   " << atoi(argv[2]) << endl;
    int fd1 = fd_get(atoi(argv[1]));
    int fd2 = fd_get(atoi(argv[2]));
    if(fd1 <= 0 || fd2 <= 0)
    {
        return -1;
    }

    while(1)
    {
        struct sockaddr_in addr;
        socklen_t len  = sizeof(addr);
        bzero(&addr,sizeof(addr));
        int accfd = accept(fd1,(struct sockaddr *)&addr,&len);
        cout << "port = " << addr.sin_port << endl;
        cout << "addr = " << inet_ntoa(addr.sin_addr) << endl;
        if (accfd < 0) {
            perror("accept err:");
            exit(0);
        }
        char c[100];
        recv(accfd,c,100,0);
        cout << c << endl;
        close(accfd);

        sleep(5);
        close(fd1);
        sleep(1);
        while(1)
        {
            int clifd = cli_fd(8888,addr.sin_port,inet_ntoa(addr.sin_addr));
            
            
            
            cout << "okkokokoko" << endl;
            if(clifd <= 0)
            {
                perror("err:");
            }
            sleep(1);
        }
    }

    std::cout << "Hello world" << std::endl;
    return 0;
}
