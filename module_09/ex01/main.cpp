#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Arguments must be like this: ./RPN \"8 2 * 9 - 6 - 9 - 8 + 2 +\"" << std::endl;
		return 0;
	}
	std::string str;
	str = av[1];
	if (str.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		return (std::cerr << "Error: Only numbers, operators, space are accepted." << std::endl);
}