#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <exception>
# include <cstdlib>
# include <limits>
# include <string>
# include <cmath>

# define MIN_INT std::numeric_limits<int>::min() //-2147483648
# define MAX_INT std::numeric_limits<int>::max() //2147483647
# define MIN_FLOAT std::numeric_limits<float>::min() //-3.40282e+38
# define MAX_FLOAT std::numeric_limits<float>::max() //3.40282e+38
# define MIN_DOUBLE std::numeric_limits<double>::min() //-1.79769e+308
# define MAX_DOUBLE std::numeric_limits<double>::max() //1.79769e+308

enum ScalarType
{
	Special = 0,
	Char = 1,
	Int = 2,
	Float = 3,
	Double = 4,
	Error = -1
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		virtual ~ScalarConverter();
	public:
		static void convert(const std::string &input);
};

ScalarType ItIs(const std::string &str);
void	specialCase(const std::string &input);
void	charCase(const std::string &input);
void	intCase(const std::string &input);
void	floatCase(const std::string &input);
void	doubleCase(const std::string &input);

#endif