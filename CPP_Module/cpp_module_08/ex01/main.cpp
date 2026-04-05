#include "Span.hpp"

int main()
{
	try
	{
		Span	smallSpan(5);
		smallSpan.addNumber(6);
		smallSpan.addNumber(3);
		smallSpan.addNumber(17);
		smallSpan.addNumber(9);
		smallSpan.addNumber(11);

		std::cout << smallSpan.shortestSpan() << std::endl;
		std::cout << smallSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Span				largeSpan(10000);
		std::vector<int>	randomValues;

		srand(time(NULL));
		for (int index = 0; index < 10000; index++)
			randomValues.push_back(rand());

		largeSpan.addNumber(randomValues.begin(), randomValues.end());

		std::cout << largeSpan.shortestSpan() << std::endl;
		std::cout << largeSpan.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
