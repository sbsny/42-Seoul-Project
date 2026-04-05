#include "convert.hpp"

static bool	isSignedNumeric(std::string const &input, bool allowTrailingF)
{
	std::size_t	index = 0;
	bool		hasDecimalPoint = false;

	if (input.empty())
		return false;
	if (input[index] == '-' || input[index] == '+')
		index++;
	if (index >= input.size())
		return false;
	for (; index < input.size(); index++)
	{
		if (allowTrailingF && index == input.size() - 1 && input[index] == 'f')
			return hasDecimalPoint;
		if (input[index] == '.')
		{
			if (hasDecimalPoint || index == 0 || index == input.size() - 1)
				return false;
			hasDecimalPoint = true;
			continue ;
		}
		if (!std::isdigit(input[index]))
			return false;
	}
	return hasDecimalPoint || !allowTrailingF;
}

static void	check_inf_nan(std::string input)
{
	if (input == "+inf" || input == "-inf" || input == "inf"
		|| input == "+inff" || input == "-inff" || input == "inff")
		display_inf(input);
	if (input == "nan" || input == "nanf")
		display_nan();
}

bool	is_char(std::string input)
{
	return input.size() == 1;
}

bool	is_int(char *input)
{
	long	numericValue = std::atol(input);
	int		charIndex = 0;

	if (numericValue > INT_MAX || numericValue < INT_MIN)
		return false;
	if (input[charIndex] == '-' || input[charIndex] == '+')
		charIndex++;
	if (input[charIndex] == '\0')
		return false;
	while (input[charIndex] != '\0')
	{
		if (!std::isdigit(input[charIndex]))
			return false;
		charIndex++;
	}
	return true;
}

bool	is_float(std::string input)
{
	return isSignedNumeric(input, true);
}

bool	is_double(std::string input)
{
	return isSignedNumeric(input, false);
}

int	main(int argumentCount, char **argumentValues)
{
	std::string	input;

	if (argumentCount != 2)
		exit(1);
	input = argumentValues[1];
	check_inf_nan(input);
	if (is_int(argumentValues[1]))
		convert_int(atoi(argumentValues[1]));
	else if (is_char(input))
		convert_char(argumentValues[1][0]);
	else if (is_float(input))
		convert_float(std::atof(argumentValues[1]));
	else if (is_double(input))
		convert_double(std::atof(argumentValues[1]));
	else
		std::cout << "Error" << std::endl;
	return 0;
}
