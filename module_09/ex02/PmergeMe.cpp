#include "PmergeMe.hpp"

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->vec = other.vec;
        this->deq = other.deq;
    }
    return *this;
}

PmergeMe::PmergeMe(std::vector<int> list) : vec(list), deq(list.begin(), list.end())
{
	std::vector<int>::iterator it = vec.begin();
	while(it != vec.end())
	{
		std::vector<int>::iterator it_checker = it;
		while(it_checker != vec.end())
		{
			it_checker++;
			if(it_checker == vec.end())
				break;
			if(it_checker != vec.end() && *it_checker == *it)
				throw dupNumber();
		}
		it++;
	}
}

size_t PmergeMe::Jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void PmergeMe::sort()
{
	clock_t tStart = clock();
	mergeInserionSort(vec);
	if(isSorted(vec))
	{
		std::cout << "Time to process a range of " << vec.size()
	             << " elements with std::[vector] : "
                  << float(clock() - tStart) / CLOCKS_PER_SEC * 1000000.0 << " us" << std::endl;
    }
	tStart = clock();
    mergeInserionSort(deq);
    if (isSorted(deq)) {
        std::cout << "Time to process a range of " << deq.size()
                  << " elements with std::[deque] : "
                  << float(clock() - tStart) / CLOCKS_PER_SEC * 1000000.0 << " us" << std::endl;
    }
}
