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
//udp client
using namespace std;

int main()
{
    int fd = socket(AF_INET,SOCK_DGRAM,0);
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8002);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    while(1)
    {
        char c[1000] = { 0 };
        memset(c,0,sizeof(c));
        cin >> c;
        sendto(fd,c,strlen(c),0,(struct sockaddr*)&addr,sizeof(addr));
        
        recvfrom(fd, c, sizeof(c),0,NULL,NULL);
        cout << c << endl;
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

