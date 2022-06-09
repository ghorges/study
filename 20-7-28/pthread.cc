#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int sum = 0;
std::atomic<int> num;
void* handle1(void *) {
    while(1) {
    if (num % 3 == 0) {
        cout << "a";
        num++;
    }    
    }
}

void* handle2(void *) {
    while(1) {
        if (num % 3 == 1) {
            cout << "b";
            num++;
        }
    }
}

void* handle3(void *) {
    while(1) {
        if (num % 3 == 2) {
            cout << "c";
            sum++;
            if (sum == 10) {
                exit(0);
            }
            num++;
        }
    }
}

int main()
{
    pthread_t t;
    pthread_create(&t, NULL, handle1, NULL);
    pthread_create(&t, NULL, handle2, NULL);
    pthread_create(&t, NULL, handle3, NULL);
    sleep(10000);
    std::cout << "Hello world" << std::endl;
    return 0;
}

