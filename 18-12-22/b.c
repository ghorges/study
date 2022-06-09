#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid > 0)
    {
        printf("grppid = %d\n",getpgrp());
        exit(0);
    }
    else
    {
        sleep(1);
        printf("my grppid = %d\n",getpgrp());
        sleep(100);
    }
    return 0;
}

