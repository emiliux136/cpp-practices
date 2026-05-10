#include <iostream>
#include <fstream>
#include <string>

void replace()

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Propper use: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    std::string filename = av[0];
    std::string pre = av[2];
    std::string post = av[3];
    replace(filename, pre, post);
    return 0;
}