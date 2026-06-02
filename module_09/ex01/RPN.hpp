#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cmath>
#include <map>
#include <fstream>
#include <vector>
#include <string>
#include <stack>

class RPN 
{
	private:
		std::string input;
		std::stack<float> list;
	public:
		//Explicit Prevents unintended object creation from a completely different data type.
		explicit RPN(char *input);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

};

#endif