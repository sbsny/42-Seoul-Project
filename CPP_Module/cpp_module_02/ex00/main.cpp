#include "Fixed.hpp"

int	main()
{
	Fixed	defaultValue;
	Fixed	copiedValue(defaultValue);
	Fixed	assignedValue;

	assignedValue = copiedValue;

	std::cout << defaultValue.getRawBits() << std::endl;
	std::cout << copiedValue.getRawBits() << std::endl;
	std::cout << assignedValue.getRawBits() << std::endl;

	return 0;
}
