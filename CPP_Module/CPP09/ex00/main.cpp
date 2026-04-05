#include "BitcoinExchange.hpp"

int	main(int argumentCount, char **argumentValues)
{
	BitcoinExchange	bitcoinExchange;

	if (argumentCount != 2)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	bitcoinExchange.parsing_data("data.csv");
	bitcoinExchange.parsing_input(argumentValues[1]);
	return 0;
}
