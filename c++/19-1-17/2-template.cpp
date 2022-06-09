#include <iostream>

using namespace std;
//1.函数模板可以像普通函数一样被重载
//2.c++编译器优先考虑普通函数
//3.如果函数模板可以产生一个更好的匹配，那么选择模板
//4.可以通过空模板实参列表的语法限定编译器只能通过模板匹配

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

