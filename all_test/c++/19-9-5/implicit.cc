#include <iostream>

template <typename To, typename From>
inline To implicit_cast(From const &f)
{
    return f;
}

class top{};
class mid1 : public top {};
class mid2 : public top {};
class downs : public mid1, public mid2 {};

void function(class mid1)
{
    std::cout << "mid1" << "\n";
}

void function(class mid2)
{
    std::cout << "mid2" << "\n";
}

int main()
{
    using std::cout;
    
    downs foo;
    function(implicit_cast<mid1>(foo));
    function(static_cast<mid1>(foo));
    
    top bar;
    function(implicit_cast<mid1>(bar));
    //function(static_cast<mid1>(foo));
    std::cout << "Hello world" << std::endl;
    return 0;
}

