#include <bits/stdc++.h>

using namespace std;


class Person
{
public:
    Person():mId(0), mAge(20){}
    void print() {
        cout << "id: " << mId << ", age: " << mAge << endl;
    }

private:
    int mId;
    int mAge;
};


int main()
{
    /* int a1;
    int a2;
    cout << "&a1 = " << &a1 << endl;
    cout << "&a2 = " << &a2 << endl;
    return 0; */

    //为什么内部是顺序的，因为要通过偏移量找这个地址
    Person p1;
    cout << "sizeof(p1) == " << sizeof(p1) << endl;
    int *p = (int*)&p1;
    cout << "p.id == " << *p << ", address: "  << p << endl;
    ++p;
    cout << "p.age == " << *p << ", address: " << p << endl;
    cout << endl;
                                    
    Person p2;
    cout << "sizeof(p2) == " << sizeof(p1) << endl;
    p = (int*)&p2;
    cout << "p.id == " << *p << ", address: " << p << endl;
    ++p;
    cout << "p.age == " << *p << ", address: " << p << endl;
    return 0;
}

