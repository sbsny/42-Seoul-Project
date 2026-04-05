#include "BitcoinExchange.hpp"

static void	exit_with_message(std::string const &message)
{
	std::cout << message << std::endl;
	std::exit(1);
}

static int	parse_integer(std::string const &text)
{
	return std::atoi(text.c_str());
}

static float	parse_float(std::string const &text)
{
	return static_cast<float>(std::atof(text.c_str()));
}

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &source)
	: rateDatabaseMap(source.rateDatabaseMap)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source)
{
	if (this != &source)
		rateDatabaseMap = source.rateDatabaseMap;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::parsing_data(std::string dataFileName)
{
	std::ifstream	dataStream(dataFileName.c_str());
	std::string		currentLine;

	if (!dataStream.is_open())
		exit_with_message("Error: data file can't be opened.");
	std::getline(dataStream, currentLine);
	while (std::getline(dataStream, currentLine))
	{
		std::size_t	commaPosition = currentLine.find(',');
		std::string	dateText;
		float		rateValue;

		if (commaPosition == std::string::npos)
			continue ;
		dateText = currentLine.substr(0, commaPosition);
		rateValue = parse_float(currentLine.substr(commaPosition + 1));
		rateDatabaseMap[dateText] = rateValue;
	}
}

void	BitcoinExchange::parsing_input(std::string inputFileName)
{
	std::ifstream	inputStream(inputFileName.c_str());
	std::string		currentLine;

	if (!inputStream.is_open())
		exit_with_message("Error: input file can't be opened.");
	while (std::getline(inputStream, currentLine))
	{
		if (currentLine == "date | value")
			continue ;
		try
		{
			std::size_t	separatorPosition;
			std::string	dateText;
			std::string	valueText;
			float		numericValue;

			if (currentLine.length() < 14 || currentLine[4] != '-'
				|| currentLine[7] != '-')
				throw std::runtime_error("Error: wrong format");
			separatorPosition = currentLine.find('|');
			if (separatorPosition == std::string::npos || separatorPosition < 2)
				throw std::runtime_error("Error: wrong format");
			dateText = currentLine.substr(0, separatorPosition - 1);
			valueText = currentLine.substr(separatorPosition + 2);
			numericValue = parse_float(valueText);
			checking_data(dateText);
			checking_value(valueText, numericValue);
			print_result(dateText, numericValue);
		}
		catch (std::exception &exception)
		{
			std::cout << exception.what() << std::endl;
		}
	}
}

bool	BitcoinExchange::if_leap(long yearValue)
{
	if (yearValue % 400 == 0)
		return true;
	if (yearValue % 100 == 0)
		return false;
	return yearValue % 4 == 0;
}

void	BitcoinExchange::checking_data(std::string dateText)
{
	std::map<std::string, float>::iterator	firstEntry = rateDatabaseMap.begin();
	int										yearValue;
	int										monthValue;
	int										dayValue;

	if (dateText.length() != 10 || dateText[4] != '-' || dateText[7] != '-')
		throw std::runtime_error("Error: wrong date");
	for (std::size_t characterIndex = 0; characterIndex < dateText.length(); characterIndex++)
	{
		if (characterIndex == 4 || characterIndex == 7)
			continue ;
		if (!std::isdigit(dateText[characterIndex]))
			throw std::runtime_error("Error: wrong date");
	}
	yearValue = parse_integer(dateText.substr(0, 4));
	monthValue = parse_integer(dateText.substr(5, 2));
	dayValue = parse_integer(dateText.substr(8, 2));
	if (firstEntry == rateDatabaseMap.end() || dateText < firstEntry->first || yearValue < 2009
		|| monthValue < 1 || monthValue > 12 || dayValue < 1 || dayValue > 31)
		throw std::runtime_error("Error: wrong date");
	if (monthValue == 2)
	{
		if (if_leap(yearValue) && dayValue > 29)
			throw std::runtime_error("Error: wrong date");
		if (!if_leap(yearValue) && dayValue > 28)
			throw std::runtime_error("Error: wrong date");
	}
	if ((monthValue == 4 || monthValue == 6 || monthValue == 9 || monthValue == 11)
		&& dayValue > 30)
		throw std::runtime_error("Error: wrong date");
}

void	BitcoinExchange::checking_value(std::string valueText, float numericValue)
{
	int	dotCount = 0;

	if (valueText.empty())
		throw std::runtime_error("Error: wrong value");
	for (std::size_t characterIndex = 0; characterIndex < valueText.length(); characterIndex++)
	{
		if ((characterIndex == 0)
			&& (valueText[characterIndex] == '+' || valueText[characterIndex] == '-'))
			continue ;
		if (valueText[characterIndex] == '.')
		{
			dotCount++;
			continue ;
		}
		if (!std::isdigit(valueText[characterIndex]))
			throw std::runtime_error("Error: wrong value");
	}
	if (dotCount > 1)
		throw std::runtime_error("Error: wrong value");
	if (numericValue < 0)
		throw std::runtime_error("Error: not a positive number.");
	if (numericValue > 1000)
		throw std::runtime_error("Error: too large a number.");
}

void	BitcoinExchange::print_result(std::string dateText, float numericValue)
{
	std::map<std::string, float>::iterator	rateIterator;

	rateIterator = rateDatabaseMap.lower_bound(dateText);
	if (rateIterator == rateDatabaseMap.end() || rateIterator->first != dateText)
		--rateIterator;
	std::cout << dateText << " => " << numericValue << " = "
		<< numericValue * rateIterator->second << std::endl;
}
