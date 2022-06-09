#include <iostream>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>


using namespace std;

int main()
{
    char *c = "www.baidu.com";
    struct hostent *hp = NULL;
    hp = gethostbyname(c);
    int i = 0;    
    while(hp->h_addr_list[i] != NULL)
        {
                            printf("hostname: %s\n",hp->h_name);
                                            printf("      ip: %s\n",inet_ntoa(*(struct in_addr*)hp->h_addr_list[i]));
                                                            i++;                                                                    
        }
    std::cout << "Hello world" << std::endl;
    return 0;
}

