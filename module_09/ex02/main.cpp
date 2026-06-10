#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr <<"Error: there arent numbers to be sorted." << std::endl;
		return 1;
	}
	std::vector<int> list;
	for(int i = 1; i < ac; i++)
	{
		std::string c = av[i];
		if (c.find_first_not_of("0123456789") != std::string::npos)
		{
			std::cerr << "Error: You can only provide positive numbers." << std::endl;
			return 1;
		}
		long double n = std::strtol(av[i], NULL, 10); //"atoi"
		if (n < 0 || n > std::numeric_limits<int>::max())
		{
			std::cerr << "Error: Invalid number provided" << std::endl;
			return 1;
		}
		list.push_back(static_cast<int>(n));
	}
	try
	{
		PmergeMe obj(list);
		PmergeMe::printPreview(list, 4, "Before: ");
		obj.sort();
		obj.printSorted();
	} 
	catch (const std::exception &e) 
	{
		std::cout << e.what() << std::endl;
	}
}