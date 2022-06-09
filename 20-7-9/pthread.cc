#include <iostream>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int* p;

void* head(void* t) {
    p = (int*)malloc(100);
    p[0] = 3;
}

void* gethead(void* t) {
    sleep(1);
    std::cout << p[0] << std::endl;
    p[3] = 5;
}

int main()
{
    pthread_t boo, far;
    if (pthread_create(&boo, NULL, &head, NULL) == -1) {
        return 0;
    }
    if (pthread_create(&far, NULL, &gethead, NULL) == -1) {
        return 0;
    }

    sleep(5);
    std::cout << p[3] << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

