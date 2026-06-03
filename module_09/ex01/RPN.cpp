#include "RPN.hpp"

bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/';
}

RPN::RPN(char *input) : inputC(input)
{
	for (size_t i = 0; i < inputC.size(); i++)
	{
		char token = inputC[i];
		if (std::isspace(token))
			continue;				 			//Skips this iteration.
		if (std::isdigit(token))
			this->list.push(std::strtof(&inputC[i], nullptr));
		else if (isOperator(token))
		{
			if(this->list.size() < 2)
			{
				throw NEN();
			}
			//Lambda function.
			auto popStack = [this]()
			{
				float value = this->list.top(); //save the top element.
				this->list.pop(); 				//returns the top element.
				return value; 					//Return it.
			};

			float operand2 = popStack(); 		//Popped first.
			float operand1 = popStack();
			switch (token)
			{
				case '+':
					list.push(operand1 + operand2);
					break;
				case '-':
					list.push(operand1 - operand2);
					break;
				case '*':
					list.push(operand1 * operand2);
					break;
				case '/':
					if(operand2 == 0.0f)
						throw NDB0();
					list.push(operand1 / operand2);
					break;
				default: 
					break;
			}
		}
	}
	if (list.size() != 1)
	{
		throw NEO();
	}
	std::cout << "result is: " << list.top() << std::endl;
}

RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN& RPN::operator=(const RPN &other)
{
	this-> inputC = other.inputC;
	this-> list = other.list;
	return *this;
}

RPN::~RPN(){}
