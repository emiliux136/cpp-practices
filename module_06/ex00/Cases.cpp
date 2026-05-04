#include "ScalarConverter.hpp"

void	specialCase(const std::string &input)
{
	if (input == "nan" || input == "nanf")
	{
		std::cout << "char: impossible" << std::endl; 
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (input == "+inf" || input == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (input == "-inf" || input == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}	
}

void	charCase(const std::string &input)
{
	int len = input.length();
	char c;
	if (len == 1)
		c = input[0];
	else
		c = input[1];
	std::cout << "char: ";
	if(isprint(c))
	{
		std::cout << "'" << c << "'" << std::endl;
		std::cout << "int: '" << static_cast<int>(c) << "'" << std::endl;
		std::cout << "float: '" << static_cast<float>(c) << ".0f'" << std::endl;
		std::cout << "double: '" << static_cast<double>(c) << ".0'" << std::endl;
	}
	else
		std::cout << "is not printable." << std::endl;
}

void	intCase(const std::string &input)
{
	long n = std::atol(input.c_str());

	std::cout << "char: ";
	if (n < 0 || n > 127)
		std::cout << "This value is not on ascii table." << std::endl;
	else
	{
		if (isprint(n))
			std::cout << "'" << static_cast<char>(n) << "'" << std::endl;
		else
			std::cout << "Conversion to char is not displayable" << std::endl;
	}
	std::cout << "int: ";
	if (n < MIN_INT || n > MAX_INT)
		std::cout << "Exceeded the limits." << std::endl;
	else
		std::cout	<< static_cast<int>(n) << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void	floatCase(const std::string &input)
{
	float f = std::atof(input.c_str());
	bool tolerance = std::fabs(f - static_cast<int>(f)) < 0.0000000000001; //with this operantion we verify if the number is extremelyclose to an integer that we can swith it.

	std::cout << "char: ";
	if (f < 0 || f > 127)
		std::cout << "This value is not on ascii table." << std::endl;
	else
	{
		if (isprint(f))
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		else
			std::cout << "Conversion to char is not displayable" << std::endl;
	}
	std::cout << "int: ";
	if (f > MAX_FLOAT || f < MIN_FLOAT)
		std::cout << "Exceeded the limits." << std::endl;
	else
		std::cout	<< static_cast<int>(f) << std::endl;
	std::cout << "float: ";
	if (f > MAX_FLOAT || f < MIN_FLOAT)
		std::cout << "Exceeded the limits." << std::endl;
	else
		std::cout << f << (tolerance ? ".0f" : "f") << std::endl; //ternary operator to clarify id the number has decimals or not.
	std::cout << "double: " << static_cast<double>(f) << (tolerance ? ".0" : "") << std::endl;
}

void	doubleCase(const std::string &input)
{
	double d = std::atof(input.c_str());
	bool tolerance = std::fabs(d - static_cast<int>(d)) < 0.0000000000001; 

	std::cout << "char: ";
	if (d < 0 || d > 127)
		std::cout << "This value is not on ascii table." << std::endl;
	else
	{
		if (isprint(d))
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "Conversion to char is not displayable" << std::endl;
	}
	std::cout << "int: ";
	if (d < MIN_INT || d > MAX_INT)
		std::cout << "Exceeded the limits." << std::endl;
	else
		std::cout	<< static_cast<int>(d) << std::endl;
	std::cout << "float: ";
	if (d > MAX_FLOAT || d < MIN_FLOAT)
		std::cout << "Exceeded the limits." << std::endl;
	else
		std::cout << static_cast<float>(d) << (tolerance ? ".0f" : "f") << std::endl;
	if (d < MIN_DOUBLE || d > MAX_DOUBLE)
		std::cout << "Exceeded the limits." << std::endl;
	else
		std::cout << "double: " << static_cast<double>(d) << (tolerance ? ".0" : "") << std::endl;
}