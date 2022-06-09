#include <stdio.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/fcntl.h>

//使用int类型测试正确
//使用mode_t
int aaa(int n, ...)
{
    va_list argptr;
    va_start(argptr, n);
    //int bar = va_arg(argptr, int);
    mode_t bar = va_arg(argptr, mode_t);
    va_end(argptr);
    return bar;
}

int opena(const char *pathname, int flags, ...)
{
    va_list argtr;
    va_start(argtr, 1);
    mode_t mode = va_arg(argtr, mode_t);
    va_end(argtr);

    int fd = open(pathname, flags, mode);
    if (fd < 0) {
        perror("??");
    }
    return mode;
}

int main()
{
    printf("Hello world %d\n", aaa(10,1));
    printf("Hello world %d\n", opena("123123", O_CREAT | O_RDWR, S_IRWXU));
    int fd = open("123test", O_CREAT | O_RDWR, 0777);
    if (fd < 0) {
        perror("err:");
    }
    return 0;
}

