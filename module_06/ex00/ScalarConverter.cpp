#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	*this = other;
}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this == &other)
		return (*this);
	return (*this);
}
ScalarConverter::~ScalarConverter()
{}

void ScalarConverter::convert(const std::string &input)
{
	ScalarType type = ItIs(input);
	switch (type)
	{
	case Error:
		std::cout << "Invalid type detected." << std::endl;	
		break;
	case Special:
		//std::cout << "===== Special Case called: =====" << std::endl;
		specialCase(input);
		break;
	case Char:
		//std::cout << "===== CHAR Case called: =====" << std::endl;
		charCase(input);
		break;
	case Int:
		//std::cout << "===== INT Case called: =====" << std::endl;
		intCase(input);
		break;
	case Float:
		//std::cout << "===== FLOAT Case called: =====" << std::endl;
		floatCase(input);
		break;
	case Double:
		//std::cout << "===== DOUBLE Case called: =====" << std::endl;
		doubleCase(input);
	default:
		break;
	}
}