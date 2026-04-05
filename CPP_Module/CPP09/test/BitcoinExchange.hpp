#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP
# include <cstdlib>
# include <cstring>
# include <ctime>
# include <fstream>
# include <iostream>
# include <map>
# include <string>

typedef struct date_s
{
	int	yearValue;
	int	monthValue;
	int	dayValue;
} date_t;

typedef std::map<std::string, float> myMap;

class BitcoinExchange
{
	private:
		std::string		_date;
		double			_value;
		std::ifstream	*_inputStream;
		myMap			*_dataMap;
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream *inputStream, myMap *dataMap);
		BitcoinExchange(const BitcoinExchange &source);
		BitcoinExchange &operator=(const BitcoinExchange &source);
		~BitcoinExchange();

		int		converter();
		int		check_line(std::string lineText);
		int		check_date(std::string &dateText);
		int		error_message(std::string message);
};

#endif
