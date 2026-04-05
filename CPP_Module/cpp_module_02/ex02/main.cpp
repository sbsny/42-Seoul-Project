#include "Fixed.hpp"

int	main()
{
	Fixed		counter;
	Fixed const	product(Fixed(5.05f) * Fixed(2));

	std::cout << counter << std::endl;
	std::cout << ++counter << std::endl;
	std::cout << counter << std::endl;
	std::cout << counter++ << std::endl;
	std::cout << counter << std::endl;

	std::cout << product << std::endl;

	std::cout << Fixed::max(counter, product) << std::endl;

	return 0;
}
