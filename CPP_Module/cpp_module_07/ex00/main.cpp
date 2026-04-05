#include "whatever.hpp"

int	main()
{
	int	firstNumber = 2;
	int	secondNumber = 3;

	::swap(firstNumber, secondNumber);
	std::cout << "a = " << firstNumber << ", b = " << secondNumber << std::endl;
	std::cout << "min(a, b) = " << ::min(firstNumber, secondNumber) << std::endl;
	std::cout << "max(a, b) = " << ::max(firstNumber, secondNumber) << std::endl;

	std::string	firstText = "chaine1";
	std::string	secondText = "chaine2";

	::swap(firstText, secondText);
	std::cout << "c = " << firstText << ", d = " << secondText << std::endl;
	std::cout << "min(c, d) = " << ::min(firstText, secondText) << std::endl;
	std::cout << "max(c, d) = " << ::max(firstText, secondText) << std::endl;

	return 0;
}
