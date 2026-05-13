#include "ScalarConverter.hpp"

//all this functions are static bc i can only use them in this file.

static int isSpecial(const std::string &str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff")
		return (1);
	return (0);
}

static int isChar(const std::string &str, size_t len)
{
	if (len == 1 && !isdigit(str[0]))
		return (1);
	if (len == 3 && str[0] == '\'' && str[2] == '\'') // validates 'a' this kinds of cases.
		return (1);
	return (0);
}

static int isInt(const std::string &str, size_t len)
{
	int i = 0;
	bool hasSing = 0;
	if(str[i] == '+' || str[i] == '-')
	{
		i++;
		hasSing = 1;
	}
	if (i == len)
		return 0;
	if(hasSing && len > 12)
		return (0);
	if(!hasSing && len > 11)
		return (0);
	while (i < len)
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int isFloat(const std::string &str, size_t len, size_t point)
{
	int i = point - 1;
	while(i >= 0)
	{
		if(!isdigit(str[i]) && i != 0)
			return (0);
		if(!isdigit(str[i]) && i == 0 && str[i] != '+' && str[i] != '-') //the first caracter if not a digit can only be - or +.
			return (0);
		i--;
	}
	i = point + 1;
	while (i < len)
	{
		if (!isdigit(str[i]) && str[i] != 'f')
			return (0);
		if (str[i] == 'f' && i != len - 1) //f can only be at the end
			return (0);
		i++;
	}
	return 1;
}

ScalarType ItIs(const std::string &str)
{
	size_t len = str.length();
	size_t point = str.find('.');
	size_t f = str.find('f');
	if (point == std::string::npos) //std::string::npos means that find didn't found anything.
	{
		if (isSpecial(str))
			return Special;
		if (isChar(str, len))
			return Char;
		if (isInt(str, len))
			return Int;
	}
	if (point != std::string::npos && f != std::string::npos)
	{
		if(isFloat(str, len, point))
			return Float;
	} 
	else if (f == std::string::npos && point != std::string::npos)
		return Double;
	return Error;
}
