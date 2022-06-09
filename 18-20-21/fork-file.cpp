#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <signal.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
using namespace std;
int main()
{
    signal(SIGCHLD,SIG_IGN);
    int fd = 0;
    fd = open("1.txt",O_RDWR);
    if(fd < 0)
    {
        perror("openerror");
        return 0;
    }
    pid_t pid;
    pid = fork();
    if(pid == -1)
    {
        cout << "pid error" << endl;
        return 0;
    }
    if(pid > 0)
    {
        sleep(1);
        write(fd,"hello",5);
        return 0;
    }else
    {
        write(fd,"world...",8);
        return 0;
    }
    return 0;
}

