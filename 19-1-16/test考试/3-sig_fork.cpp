#include <iostream>
#include <signal.h>
#include <cstdio>
#include <cstring>
#include <errno.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;
/*
 *   int sigaction(int signum, const struct sigaction *act,
 *                        struct sigaction *oldact);
 */
/*
 * int sigqueue(pid_t pid, int sig, const union sigval value);
 */

void child1hand(int a,siginfo_t *p,void *q)
{

}
void child1()
{
    struct sigaction act;
    act.sa_sigaction = child1hand;
    act.sa_flags = 1;

    sigaction(SIGRTMIN,NULL);
}

void child2()
{

}
int main()
{
    int pid = fork();
    if(pid < 0)
    {
        perror("fork err:");
        return -1;
    }
    if(pid == 0)//子1进程
    {
        child1();
    }
    pid = 0;
    pid = fork();
    
    if(pid < 0)
    {   
        perror("fork err:");
        return -1; 
    }   
    if(pid == 0)//子2进程
    {
        child2();
    }

    std::cout << "Hello world" << std::endl;
    return 0;
}

