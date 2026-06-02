#include "BitcoinExchange.hpp"
#include <sstream>
#include <cstdlib>

static const char *WHITESPACE = " \t\n\r";

static std::string &ltrim(std::string &str)
{
	str.erase(0, str.find_first_not_of(WHITESPACE));
	return str;
}

static std::string &rtrim(std::string &str)
{
	std::string::size_type pos = str.find_last_not_of(WHITESPACE);
	if (pos == std::string::npos)
	{
		str.clear();
		return str;
	}
	str.erase(pos + 1);
	return str;
}

static std::string &trim(std::string &str)
{
	return ltrim(rtrim(str));
}

Bitcoin::Bitcoin() : flag(1)
{
	std::ifstream file("./data.csv");
	std::string line;

	if (!file.is_open())
	{
		this->flag = 0;
		return;
	}
	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::string::size_type comma = line.find(',');
		std::string date;
		double value;

		if (comma == std::string::npos)
			continue;
		date = line.substr(0, comma);
		date = trim(date);
		try
		{
			std::stringstream ss(line.substr(comma + 1));
			ss >> value;
			if (ss.fail() || !ss.eof())
				continue;
		}
		catch (...)
		{
			continue;
		}
		this->values.insert(std::make_pair(date, static_cast<float>(value)));
	}
}

Bitcoin::Bitcoin(Bitcoin const &other)
{
	*this = other;
}

Bitcoin& Bitcoin::operator=(Bitcoin const &other)
{
	this->values = other.values;
	return *this;
}

std::map <std::string, float> Bitcoin::GetValues()
{
	return (this->values);
}

Bitcoin::~Bitcoin(){}

/*Ensure is openable and open it. If not informs.*/
std::ifstream Bitcoin::IsOpenable(std::string inputPath)
{
	std::ifstream file(inputPath);
	if(!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		this->flag = -1;
		return std::ifstream();
	}
	return file;
}

bool Bitcoin::parseLine( const std::string& line, std::string& date, double& value)
{
	std::string::size_type pipe = line.find('|');
	std::string left;
	std::string right;
	std::stringstream stream;

	if (pipe == std::string::npos)
	{
		std::cout << "Error: bad input => " << line << std::endl;
		return false;
	}
	left = line.substr(0, pipe);
	right = line.substr(pipe + 1);
	trim(left);
	trim(right);
	if (left.empty() || right.empty())
	{
		std::cout << "Error: bad input => " << left << std::endl;
		return false;
	}
	stream.str(right);
	stream >> value;
	if (stream.fail() || !stream.eof())
	{
		std::cout << "Error : Input Not A Number" << std::endl;
		return false;
	}
	if (value > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return false;
	}
	if (value < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return false;
	}
	date = left;
	return true;
}

float Bitcoin::findRate(const std::string& date)
{
	std::map<std::string, float>::iterator it;
	std::string lookup = date;

	trim(lookup);
	if (this->values.empty())
		return 0.0f;
	it = this->values.upper_bound(lookup);
	if (it == this->values.begin())
		return it->second;
	if (it == this->values.end())
	{
		--it;
		return it->second;
	}
	--it;
	return it->second;
}

/*The function that prints the result. 
Firstly calls the parser and then findRate.*/
void Bitcoin::processLine(const std::string& line)
{
	std::string date;
	double value;

	if(!parseLine(line, date, value))
		return;
	float rate = findRate(date);
	std::cout << date
			  << " => "
			  << value
			  << " = "
			  << value * rate
			  << std::endl;
}	

/*Starts the reading the input file, ensure is openable and send it to processement*/
void Bitcoin::ReadInfo(std::string inputPath)
{
	std::ifstream file = IsOpenable(inputPath);
	if (!file)
		return;	
	std::string line;
	std::getline(file, line); // skiping header
	while (std::getline(file, line))
	{
		processLine(line);
	}
}