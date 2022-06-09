#include <bits/stdc++.h>

using namespace std;

class A
{
public:
    virtual void print() {
        cout << "This is class A." << endl;
    }
};

class B : public A
{
public:
    virtual void print() {
        cout << "This is class B." << endl;
    }
};

int main()
{
    A *a = new B;
    a->print();
    cout << typeid(a).name() << endl;
    cout << typeid(*a).name() << endl;
    /*
    A *pa = NULL;
    cout << typeid(pa).name() << endl;

    A a;
    cout << typeid(a).name() << endl;
    */
    //int a = 10;
    //cout << typeid(a).name() << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

