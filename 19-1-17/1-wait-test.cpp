#include <iostream>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{
    int pid = fork();
    if(pid > 0)
    {
        int ppid = fork();
            
    }
    else if(pid == 0)
    {
        sleep(100);
    }
    wait(NULL);
    std::cout << "Hello world" << std::endl;
    return 0;
}

