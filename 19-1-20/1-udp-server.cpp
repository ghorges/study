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
//udp server
using namespace std;

int main()
{
    int fd = socket(AF_INET,SOCK_DGRAM,0);
    if(fd < 0)
    {
        perror("sock err:");
        return -1;
    }
/*
     *  int bind(int sockfd, const struct sockaddr *addr,
     *                  socklen_t addrlen);
*/
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8002);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if(bind(fd,(struct sockaddr*)&addr,sizeof(addr)) < 0)
    {
        perror("bind err:");
        return -1;
    }

    char c[1024] = { 0 };
    struct sockaddr_in re_addr;
    socklen_t re_len = sizeof(re_addr);

    while(1)
    {
        memset(c,0,sizeof(c));
        int n = recvfrom(fd,c,sizeof(c),0,(struct sockaddr*)&re_addr,&re_len);
        cout << c << endl;

        sendto(fd,c,strlen(c),0,(struct sockaddr*)&re_addr,re_len);
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

