#pragma once

#include <algorithm>
#include <exception>
#include <iterator>
#include <iostream>

class NotFound : public std::exception
{
	public:
	const char* what() const noexcept override 
	{
		return ("Not Found");
	}
};

template <typename T>
typename T::iterator easyfind(T &input, int search)
{
	typename T::iterator i;
	i = std::find(input.begin(), input.end(), search);
	if (i == input.end())
	{
		throw (NotFound());
	}
	return (i);
}
