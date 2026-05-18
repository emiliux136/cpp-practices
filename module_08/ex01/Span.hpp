#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <algorithm>
# include <cmath>
# include <vector>


class Span
{
	private:
		std::vector<int> storage;
		unsigned int size;
		unsigned int pos;

		Span();
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		unsigned int getSize() const;
		unsigned int getPos() const;
		void addNumber(unsigned int N);
		unsigned int shortestSpan();
		unsigned int longestSpan();

	class InvalidVector : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return("Invalid or broken vector.");
			}
	};

	class FulledVector : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return("Span is Full.");
		}
	};

	class OnlyOneNumber : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return("No Span can be found. Empty or only one element.");
		}
	};
};

// Utility: generate a vector of `n` random integers in [minv, maxv]
std::vector<int> generate_random_list(size_t n, int minv = 0, int maxv = 100000);

#endif