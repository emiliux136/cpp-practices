#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <exception>
#include <ctime>
#include <limits>
#include <deque>
#include <algorithm>


class PmergeMe
{
	private:
		PmergeMe();
		template<typename Container> static bool isSorted(Container & cont);
		std::vector<int> vec;
		std::deque<int> deq;
	public:
		explicit PmergeMe(std::vector<int> list);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		static size_t Jacobsthal(size_t n);
		void sort();
		void printSorted() const;
		template<typename Container> static void printList(const Container &cont);

		class dupNumber : public std::exception 
		{
			public: 
				const char *what() const throw()
				{
					return("Error: There are duplicated numbers.");
				}
		};
	};

	template <typename Container>
	bool PmergeMe::isSorted(Container &cont)
	{
		for (typename Container::size_type i = 1; i < cont.size(); ++i)
		{
			if (cont[i - 1] > cont[i])
				return false;
		}
		return true;
	}

	template <typename Container> 
void mergeInserionSort(Container &cont)
{
	if (cont.size() <= 1)
		return;

	Container lil;
	Container main;
	int lilElement = -1;
	bool hasLil = false;

	if (cont.size() % 2 != 0) // Save if odd (inpar),the last number of the list.
	{
		lilElement = cont.back();
		cont.pop_back();
		hasLil = true;
	}

	for (size_t i = 0; i < cont.size(); i += 2) //Compare and divide in to chains.
	{
		if (cont[i] > cont[i + 1])
		{
			main.push_back(cont[i]);
			lil.push_back(cont[i + 1]);
		} else {
			main.push_back(cont[i + 1]);
			lil.push_back(cont[i]);
		}
	}
	mergeInserionSort (main); // Sort recursively the main chain
	main.insert(main.begin(), lil[0]);

	size_t jIndex = 3;
	size_t lastInserted = 1;

	while (lastInserted < lil.size())
	{
		size_t jacobNum = PmergeMe::Jacobsthal(jIndex);
		size_t endGroup = (jacobNum < lil.size()) ? jacobNum : lil.size();
		for (long long i = static_cast<long long>(endGroup) - 1; i >= static_cast<long long>(lastInserted); i--)
		{
			typename Container::iterator it = std:: lower_bound(main.begin(), main.end(), lil[i]);
			main.insert(it, lil[i]);
		}
		lastInserted = endGroup;
		jIndex++;
	}
	if (hasLil)
	{
		typename Container::iterator it = std:: lower_bound(main.begin(), main.end(), lilElement);
		main.insert(it, lilElement);
	}
	cont = main;
}

template <typename Container>
void PmergeMe::printList(const Container &cont)
{
	bool first = true;
	typename Container::const_iterator it = cont.begin();
	while (it != cont.end())
	{
		if (!first)
			std::cout << ' ';
		std::cout << *it;
		first = false;
		++it;
	}
	std::cout << std::endl;
}
#endif