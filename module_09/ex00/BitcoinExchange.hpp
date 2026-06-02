#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cmath>
#include <map>
#include <fstream>
#include <vector>
#include <string>

class Bitcoin
{
	private:
		std::map <std::string, float> values;
		int flag;

	public:
		Bitcoin();
		Bitcoin(Bitcoin const &other);
		Bitcoin& operator=(Bitcoin const &other);
		~Bitcoin();

		std::map <std::string, float> GetValues();
		void ReadInfo(std::string inputPath);
		std::ifstream IsOpenable(std::string inputPath);
		void processLine(const std::string& line);
		bool parseLine( const std::string& line, std::string& date, double& value);
		float findRate(const std::string& date);
};

#endif