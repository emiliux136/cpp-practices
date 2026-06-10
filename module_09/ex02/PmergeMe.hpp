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
		template<typename Container> static void printPreview(const Container &cont, size_t limit, const std::string &prefix);

		class dupNumber : public std::exception 
		{
			public: 
				const char *what() const throw()
				{
					return("Error: There are duplicated numbers.");
				}
		};
};

//Check if the chain is sorted by comparing number to number.
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

/*inserts valueToInsert into mainChain but only in the subrange before its paired winnerValue.
It finds the winner's position then uses lower_bound on [begin, winnerIt) to place the value in sorted order while keeping the insertion bounded*/
template <typename Container>
void insertBeforeItsWinner(Container &mainChain, const typename Container::value_type &valueToInsert, const typename Container::value_type &winnerValue)
{
	typename Container::iterator winnerIt = std::find(mainChain.begin(), mainChain.end(), winnerValue);
	typename Container::iterator insertIt = std::lower_bound(mainChain.begin(), winnerIt, valueToInsert);
	mainChain.insert(insertIt, valueToInsert);
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

	for (size_t i = 0; i < cont.size(); i += 2) //Compare and divide in two chains.
	{
		// Pair adjacent elements: the larger (winner) goes to `main`, the smaller (loser) goes to `lil`.
		// This splits the list into winners to be recursively sorted and losers to be inserted later.
		if (cont[i] > cont[i + 1])
		{
			main.push_back(cont[i]);
			lil.push_back(cont[i + 1]);
		} else {
			main.push_back(cont[i + 1]);
			lil.push_back(cont[i]);
		}
	}
	Container pairedWinners = main;
	mergeInserionSort (main); // Sort recursively the main chain
	insertBeforeItsWinner(main, lil[0], pairedWinners[0]);

	size_t jIndex = 3;
	size_t lastInserted = 1;

	while (lastInserted < lil.size())
	{
		// Process losers in Jacobsthal-defined groups: take a batch of losers (size determined by Jacobsthal numbers) and insert them into `main`.
		size_t jacobNum = PmergeMe::Jacobsthal(jIndex);
		size_t endGroup = (jacobNum < lil.size()) ? jacobNum : lil.size();
		// Insert losers from the current group in reverse order so later inserts do not invalidate the insertion bounds of earlier losers in this group.
		for (long long i = static_cast<long long>(endGroup) - 1; i >= static_cast<long long>(lastInserted); i--)
		{
			// For each loser, insert it only in the sorted range before its paired winner to preserve the bounded-insertion property of Ford-Johnson.
			insertBeforeItsWinner(main, lil[i], pairedWinners[i]);
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

template <typename Container>
void PmergeMe::printPreview(const Container &cont, size_t limit, const std::string &prefix)
{
	std::cout << prefix;
	size_t printed = 0;
	typename Container::const_iterator it = cont.begin();
	for (; it != cont.end() && printed < limit; ++it, ++printed)
	{
		if (printed)
			std::cout << ' ';
		std::cout << *it;
	}
	if (cont.size() > limit)
		std::cout << " [...]";
	std::cout << std::endl;
}
#endif