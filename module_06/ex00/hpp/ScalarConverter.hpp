#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <exception>
#include <cstdlib>
#include <limits>
#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		virtual ~ScalarConverter();
	public:
		static void convert(std::string);
};

#endif