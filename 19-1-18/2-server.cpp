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

    while(1)
    {
        char c[100];
        recv(acc_fd,c,100,0);
        cout << c << endl;
    }
    

    std::cout << "Hello world" << std::endl;
    return 0;
}

