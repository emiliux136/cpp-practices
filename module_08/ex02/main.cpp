#include "MutantStack.hpp"

#include <list>

template <typename Iterator>
void printRange(Iterator first, Iterator last)
{
	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}
}

void testMutantStack()
{
	std::cout << "====== Testing MutantStack: ======" << std::endl;
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	printRange(it, ite);

	std::stack<int> s(mstack);
	(void)s;
}

void testStackMembers()
{
	std::cout << "====== Testing stack members: ======" << std::endl;
	MutantStack<int> stack;
	MutantStack<int> copy;

	std::cout << stack.empty() << std::endl;

	stack.push(10);
	stack.push(20);

	std::cout << "Top:" << stack.top() << std::endl;
	std::cout << "Size:" << stack.size() << std::endl;

	copy = stack;
	stack.pop();

	std::cout << "Top:" << stack.top() << std::endl;
	std::cout << "Copy top:" << copy.top() << std::endl;
	std::cout << "Copy empty:" << copy.empty() << std::endl;
	std::cout << std::endl;
}

void testList()
{
	std::cout << "====== Testing List: ======" << std::endl;
	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;

	lst.pop_back();

	std::cout << lst.size() << std::endl;

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;

	printRange(it, ite);
}

int main()
{
	testStackMembers();
	testMutantStack();
	testList();
	return 0;
}