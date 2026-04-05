#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	rateDatabaseMap;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &source);
		BitcoinExchange &operator=(const BitcoinExchange &source);
		~BitcoinExchange();

		void	parsing_data(std::string dataFileName);
		void	parsing_input(std::string inputFileName);
		void	checking_data(std::string dateText);
		void	checking_value(std::string valueText, float numericValue);
		void	print_result(std::string dateText, float numericValue);
		bool	if_leap(long yearValue);
};

#endif
