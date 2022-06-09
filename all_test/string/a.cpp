#include <iostream>
#include <string>

using namespace std;

class a
{
public:
    typedef char* iterator;

};
int main()
{
    a::iterator ttt;
    ttt = "1111111111111";
    cout << ttt << endl;

















    string s1("qwe123456");
    for(string::iterator t = s1.begin();t != s1.end();t++)
    {
        cout << *t << endl;
    }
    cout << s1 << endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

