#include <bits/stdc++.h>

using namespace std;

int main()
{
    shared_ptr <int> p(new int);
    *p = 5;
    cout << *p << endl;

    // 一般的初始化方式
    shared_ptr<string> foo(new string("1212"));
    cout << *foo << endl;
    
    // 推荐的安全的初始化方式
    shared_ptr<string> bar = make_shared<string>("123123");
    cout << bar << endl;
    cout << *bar << endl;
    
    // 更简单的方式
    auto tra = make_shared<string>("222");
    cout << *tra << endl;
    std::cout << "Hello world" << std::endl;
    
    return 0;
}

