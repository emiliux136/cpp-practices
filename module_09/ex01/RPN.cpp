#include "RPN.hpp"

RPN::RPN(char *input) 
{}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN &other)
{
	this-> input = other.input;
	this-> list = other.list;
	return *this;
}

RPN::~RPN(){}
