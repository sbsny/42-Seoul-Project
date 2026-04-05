#include "Fixed.hpp"

int	main()
{
	Fixed		defaultValue;
	Fixed const	integerValue(10);
	Fixed const	floatValue(42.42f);
	Fixed const	copiedValue(integerValue);

	defaultValue = Fixed(1234.4321f);

	std::cout << "a is " << defaultValue << std::endl;
	std::cout << "b is " << integerValue << std::endl;
	std::cout << "c is " << floatValue << std::endl;
	std::cout << "d is " << copiedValue << std::endl;

	std::cout << "a is " << defaultValue.toInt() << " as integer" << std::endl;
	std::cout << "b is " << integerValue.toInt() << " as integer" << std::endl;
	std::cout << "c is " << floatValue.toInt() << " as integer" << std::endl;
	std::cout << "d is " << copiedValue.toInt() << " as integer" << std::endl;

	return 0;
}
