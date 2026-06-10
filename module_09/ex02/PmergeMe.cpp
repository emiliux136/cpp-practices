#include "PmergeMe.hpp"

// Destructor
PmergeMe::~PmergeMe(){}

// Copy constructor.
PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq) {}

// Assignation operator from orthodox canonycal form.
PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
    if (this != &other) {
        this->vec = other.vec;
        this->deq = other.deq;
    }
    return *this;
}

// Constructor. Initializes vec by copying list and builds deq from the same values.
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

/*computes and returns the n-th Jacobsthal number (J0=0, J1=1, Jn=J(n-1)+2·J(n-2)).
It's used to determine the batched insertion sizes/order (Jacobsthal-driven groups) in the merge‑insertion sorting phase.*/
size_t PmergeMe::Jacobsthal(size_t n)
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

/* Tree funcion that calls the real algorithm, countss 
and displays the time that the two containers take to be sorted. */
void PmergeMe::sort()
{
	clock_t tStart = clock();
	mergeInserionSort(vec);
	{
		bool sortedVec = isSorted(vec);
		std::cout << "Time to process a range of " << vec.size()
		          << " elements with std::[vector] : "
		          << float(clock() - tStart) / CLOCKS_PER_SEC * 1000000.0 //multiply to get the exact
				  << " us";		//  number of microsecond, (there are 1.000.000 microseconds in a single second).
		std::cout << std::endl;

	}
	tStart = clock();
    mergeInserionSort(deq);
	{
		bool sortedDeq = isSorted(deq);
		std::cout << "Time to process a range of " << deq.size()
		          << " elements with std::[deque] : "
		          << float(clock() - tStart) / CLOCKS_PER_SEC * 1000000.0 
				  << " us";
		std::cout << std::endl;
	}
}

void PmergeMe::printSorted() const
{
	PmergeMe::printPreview(vec, 4, "After: ");
	//PmergeMe::printList(vec);
}
