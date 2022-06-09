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

using namespace std;

int recvss(int fd)
{
    bool flags = 1;
    int n = 0;
    while(flags)
    {
        int i = 0;
        char c[1024] = { 0 };
        int t = recv(fd,c,1024,MSG_PEEK);
        if(t < 0)
        {
            if(errno == EINTR)
                continue;
            return -1;
        }
        for(i = 0;i < t;i++)
        {
            if(c[i] == '\n')
            {
                flags = 0;
                break;
            }
        }
        n += i;
    }
    return n;
}
int main()
{
    //同理，先产出套接字
    int sockfd = 0;
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    if(sockfd == -1)
    {
        perror("socket err:");
        return -1;
    }

/*
int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
*/
    struct sockaddr_in connaddr;
    memset(&connaddr,0,sizeof(connaddr));
    connaddr.sin_family = AF_INET;
    connaddr.sin_port = htons(8008);
    connaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    //绑定端口，ip之类的
    if(bind(sockfd,(struct sockaddr *)&connaddr,sizeof(connaddr)) < 0)
    {
        perror("conn err:");
        return -1;
    }
    //监听，注意，listen中有两个队列，一个是正在握手的，一个是握手完成的
    if(listen(sockfd,20) < 0)
    {
        perror("listen err:");
        return -1;
    }
    
/*
 *  int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
 */
    struct sockaddr_in acc_addr;
    memset(&acc_addr,0,sizeof(acc_addr));
    socklen_t acc_len;
    memset(&acc_len,0,sizeof(acc_len));
    //accept！
    int accfd = accept(sockfd,(struct sockaddr *)&acc_addr,&acc_len);

    if(accfd < 0)
    {
        perror("accept err:");
        return -1;
    }

    while(1)
    {
        int n = recvss(accfd);
        cout << "n = " << n << endl;
    }

    std::cout << "Hello world" << std::endl;
    return 0;
}

