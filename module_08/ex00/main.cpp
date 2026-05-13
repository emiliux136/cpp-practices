#include "easyfind.hpp"

#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename T>
void testContainer(T &container, int value)
{
	try
	{
		typename T::iterator it = easyfind(container, value);
		std::cout << "Found " << value << " at value " << *it << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Searching for " << value << ": " << e.what() << std::endl;
	}
}

int main()
{
	/*A vector stores elements in one contiguous block of memory (like a dynamic array).*/
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(20);

	//chain of linked nodes Each element stores the value, a pointer to next node and a pointer to previous node
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	//lst.push_back(-1);
	lst.push_back(3);
	lst.push_back(2);

	/*A deque is not stored contiguously. Internally it uses multiple memory blocks.*/
	std::deque<int> deq;
	deq.push_back(7);
	deq.push_back(8);
	deq.push_back(9);

	std::cout << "\nVector tests" << std::endl;
	testContainer(vec, 20);
	testContainer(vec, 30);
	testContainer(vec, 99);

	std::cout << "\nList tests" << std::endl;
	testContainer(lst, 2);
	testContainer(lst, -1);

	std::cout << "\nDeque tests" << std::endl;
	testContainer(deq, 7);
	testContainer(deq, 3);

	return 0;
}
