#include "convert.hpp"

static bool	hasFractionalPart(double numericValue)
{
	return numericValue != static_cast<int>(numericValue);
}

void	convert_char(char characterValue)
{
	std::cout << "char: '" << characterValue << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(characterValue) << std::endl;
	std::cout << "float: " << static_cast<float>(characterValue) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(characterValue) << ".0" << std::endl;
}

void	convert_int(int integerValue)
{
	display_char(static_cast<double>(integerValue));
	std::cout << "int: " << integerValue << std::endl;
	std::cout << "float: " << static_cast<float>(integerValue) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(integerValue) << ".0" << std::endl;
}

void	convert_float(float floatValue)
{
	double	numericValue = static_cast<double>(floatValue);

	display_char(numericValue);
	std::cout << "int: ";
	if (numericValue > INT_MAX || numericValue < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(floatValue) << std::endl;
	std::cout << "float: " << floatValue;
	if (!hasFractionalPart(numericValue))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << numericValue;
	if (!hasFractionalPart(numericValue))
		std::cout << ".0";
	std::cout << std::endl;
}

void	convert_double(double doubleValue)
{
	display_char(doubleValue);
	std::cout << "int: ";
	if (doubleValue > INT_MAX || doubleValue < INT_MIN)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(doubleValue) << std::endl;
	std::cout << "float: " << static_cast<float>(doubleValue);
	if (!hasFractionalPart(doubleValue))
		std::cout << ".0";
	std::cout << "f" << std::endl;
	std::cout << "double: " << doubleValue;
	if (!hasFractionalPart(doubleValue))
		std::cout << ".0";
	std::cout << std::endl;
}
