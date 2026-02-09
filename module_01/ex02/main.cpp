#include <string>
#include <iostream>

int main()
{
    std::string s = "HI THIS IS BRAIN";
    std::string *pointer = &s;
    std::string &reference = s;

    std::cout << &s << std::endl;
    std::cout << pointer << std::endl;
    std::cout << &reference << std::endl;

    std::cout << s << std::endl;
    std::cout << &pointer << std::endl;
    std::cout << reference << std::endl;
}