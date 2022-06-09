#include <iostream>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <signal.h>
//先让服务器的子进程接受数据，然后close，然后让父进程接受数据，成功！
using namespace std;

int main()
{
    int fd = socket(AF_INET,SOCK_STREAM,0);
    if(fd == -1)
    {
        perror("soc err:");
        return -1;
    }
    int yes = 1;
    if(setsockopt(fd,SOL_SOCKET,SO_REUSEADDR,&yes,sizeof(yes)) < 0)
    {
        perror("setso err:");
        return -1;
    }

    struct sockaddr_in bin_addr;
    bin_addr.sin_family = AF_INET;
    bin_addr.sin_port = htons(8008);
    bin_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(bind(fd,(struct sockaddr*)&bin_addr,sizeof(bin_addr)) < 0)
    {
        perror("bind err:");
        return -1;
    }
    
    if(listen(fd,20) < 0)
    {
        perror("listen err:");
        return -1;
    }

    struct sockaddr_in acc_addr;
    memset(&acc_addr,0,sizeof(acc_addr));
    socklen_t len = sizeof(acc_addr);
    int acc_fd = accept(fd,(struct sockaddr*)&acc_addr,&len);
    int pid = fork();
    if(pid > 0)
    {
        int i = 9;
        while(i--)
        {
            sleep(1);
        }
        while(1)
        {
            char c[100];
            memset(c,0,sizeof(c));
            int d = recv(acc_fd,c,100,0);
            if(d == 0)
            {
                cout << "被关闭" << endl;
                break;
            }
            if(d < 0)
            {
                cout << "err" << endl;
                break;
            }
            cout << c << endl;
        }
    }

    if(pid == 0)
    while(1)
    {
        static int i = 5;
        if(i == 0)
        {
            //close(fd);
            shutdown(fd,SHUT_RD);
            break;
        }
        char c[100];
        recv(acc_fd,c,100,0);
        cout << c << endl;
        cout << "i = " << i << endl;
        i--;
    }

    std::cout << "Hello world" << std::endl;
    return 0;
}

