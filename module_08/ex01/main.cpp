#include "Span.hpp"
#include <iostream>

int main()
{
	try {
		const size_t N = 10001;
		std::vector<int> nums = generate_random_list(N, 0, 1000000);

		Span sp(N);
		for (size_t i = 0; i < nums.size(); ++i)
			sp.addNumber(nums[i]);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (const Span::OnlyOneNumber &e) {
		std::cerr << "OnlyOneNumber: " << e.what() << std::endl;
	}
	catch (const Span::FulledVector &e) {
		std::cerr << "FulledVector: " << e.what() << std::endl;
	}
	catch (const std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// test exception handling for single-element span
	try {
		Span ssmall(1);
		std::vector<int> one = generate_random_list(1);
		ssmall.addNumber(one[0]);
		std::cout << "Attempting shortestSpan() on single-element span..." << std::endl;
		std::cout << ssmall.shortestSpan() << std::endl;
	}
	catch (const Span::OnlyOneNumber &e) {
		std::cerr << "Caught OnlyOneNumber as expected: " << e.what() << std::endl;
	}

	return 0;
}