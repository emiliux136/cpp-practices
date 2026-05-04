#include "../hpp/ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}
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