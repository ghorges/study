#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

using namespace std;

int main()
{
    close(0);
    open("www.txt",O_RDONLY);
    close(1);
    open("www2.txt",O_WRONLY | O_CREAT| O_TRUNC,0644);

    execlp("cat","cat",NULL);

    std::cout << "Hello world" << std::endl;
    return 0;
}

