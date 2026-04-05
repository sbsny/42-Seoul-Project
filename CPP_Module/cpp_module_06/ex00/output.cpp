#include "convert.hpp"

void	display_char(double numericValue)
{
	int	characterCode = static_cast<int>(numericValue);

	if (characterCode > 127 || characterCode < 0)
		std::cout << "char: impossible" << std::endl;
	else if (characterCode < 32 || characterCode == 127)
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(numericValue) << "'" << std::endl;
}

void	display_inf(std::string input)
{
	std::string	floatValue = input;
	std::string	doubleValue = input;

	if (doubleValue[0] == '+')
		doubleValue.erase(0, 1);
	if (floatValue[floatValue.size() - 1] != 'f')
		floatValue.append("f");
	if (doubleValue[doubleValue.size() - 1] == 'f')
		doubleValue.erase(doubleValue.size() - 1);
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << floatValue << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
	exit(0);
}

void	display_nan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
	exit(0);
}
