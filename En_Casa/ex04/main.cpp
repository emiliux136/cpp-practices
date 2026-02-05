#include <iostream>
#include <fstream>
#include <string>

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Propper use: " << av[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
}