#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//exit && _exit
int main()
{
    printf("Hello world");
    //exit(0);
    _exit(0);
}

