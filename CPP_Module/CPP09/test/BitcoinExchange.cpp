#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
	: _date(""), _value(0), _inputStream(NULL), _dataMap(NULL)
{
}

BitcoinExchange::BitcoinExchange(std::ifstream *inputStream, myMap *dataMap)
	: _date(""), _value(0), _inputStream(inputStream), _dataMap(dataMap)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
	: _date(source._date), _value(source._value),
	_inputStream(source._inputStream), _dataMap(source._dataMap)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source)
{
	if (this != &source)
	{
		this->_date = source._date;
		this->_value = source._value;
		this->_inputStream = source._inputStream;
		this->_dataMap = source._dataMap;
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

int	BitcoinExchange::error_message(std::string message)
{
	std::cout << message << std::endl;
	return 0;
}

int	BitcoinExchange::check_date(std::string &dateText)
{
	struct tm	calendarDate;
	time_t		convertedTime;
	date_t		dateParts;

	dateParts.yearValue = std::atoi(dateText.substr(0, 4).c_str()) - 1900;
	dateParts.monthValue = std::atoi(dateText.substr(5, 2).c_str()) - 1;
	dateParts.dayValue = std::atoi(dateText.substr(8, 2).c_str());
	std::memset(&calendarDate, 0, sizeof(calendarDate));
	calendarDate.tm_year = dateParts.yearValue;
	calendarDate.tm_mon = dateParts.monthValue;
	calendarDate.tm_mday = dateParts.dayValue;
	convertedTime = std::mktime(&calendarDate);
	if (convertedTime == -1 || calendarDate.tm_year != dateParts.yearValue
		|| calendarDate.tm_mon != dateParts.monthValue
		|| calendarDate.tm_mday != dateParts.dayValue)
		return 0;
	return 1;
}

int	BitcoinExchange::check_line(std::string lineText)
{
	this->_date = lineText.substr(0, 10);
	if (lineText.length() < 14 || lineText[4] != '-' || lineText[7] != '-'
		|| !check_date(this->_date))
		return error_message("Error: bad input => " + lineText);
	this->_value = std::atof(lineText.substr(13).c_str());
	if (this->_value < 0)
		return error_message("Error: not a positive number.");
	if (this->_value > 1000)
		return error_message("Error: too large a number.");
	return 1;
}

int	BitcoinExchange::converter()
{
	std::string		currentLine;
	myMap::iterator	rateIterator;

	std::getline(*this->_inputStream, currentLine);
	while (std::getline(*this->_inputStream, currentLine))
	{
		if (!check_line(currentLine))
			continue ;
		rateIterator = this->_dataMap->upper_bound(currentLine.substr(0, 10));
		--rateIterator;
		std::cout << this->_date << " => " << this->_value << " = "
			<< rateIterator->second * this->_value << std::endl;
	}
	return 0;
}
