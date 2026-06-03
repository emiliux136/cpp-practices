#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cmath>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <stack>
#include <exception>

class RPN 
{
	private:
		std::string inputC;
		std::stack<float> list;
	public:
		//Explicit Prevents unintended object creation from a completely different data type.
		explicit RPN(char *input);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

	class NDB0: public std::exception 
	{
		public:
			const char *what() const throw()
			{
				return ("Error: Non divisable by zero.");
			}
	};
	class NEN: public std::exception 
	{
		public:
			const char *what() const throw()
			{
				return ("Error: There aren't enough numbers to complete the operation.");
			}
	};
	class NEO: public std::exception 
	{
		public:
			const char *what() const throw()
			{
				return ("Error: There aren't enough operators to complete the operation.");
			}
	};
};

#endif