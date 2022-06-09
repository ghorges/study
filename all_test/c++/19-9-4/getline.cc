#include <iostream>
#include <string>

using std::string;

/*
 * template< class CharT, class Traits, class Allocator >
 * std::basic_istream<CharT,Traits>& getline( std::basic_istream<CharT,Traits>& input,
 * std::basic_string<CharT,Traits,Allocator>& str,
 * CharT delim );
 */

int main()
{
    string foo;
    //getline(std::cin, foo);
    //The third vages is the flag to end this things
    getline(std::cin, foo, ' ');

    std::cout << foo << "\n";
    std::cout << "Hello world" << std::endl;
    return 0;
}

