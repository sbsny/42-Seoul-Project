#include "BitcoinExchange.hpp"

int	error_print2(std::string message)
{
	std::cout << message << std::endl;
	exit(1);
}

int	main(int argumentCount, char **argumentValues)
{
	std::string		currentLine;
	std::ifstream	inputStream;
	std::ifstream	dataStream;
	myMap			dataMap;

	if (argumentCount != 2)
		return error_print2("Error");
	inputStream.open(argumentValues[1], std::ifstream::in);
	dataStream.open("./data.csv", std::ifstream::in);
	if (!dataStream)
		return error_print2("Error: Data file can't be opened.");
	if (!inputStream)
		return error_print2("Error: Input file can't be opened.");
	std::getline(dataStream, currentLine);
	while (std::getline(dataStream, currentLine))
		dataMap[currentLine.substr(0, 10)] = atof(currentLine.substr(11).c_str());

	BitcoinExchange	bitcoinExchange(&inputStream, &dataMap);
	bitcoinExchange.converter();

	inputStream.close();
	dataStream.close();
	return 0;
}
