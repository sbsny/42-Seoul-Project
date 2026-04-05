#include "Fixed.hpp"

Fixed::Fixed() : storedValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const integerValue) : storedValue(integerValue << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const floatingValue)
	: storedValue(roundf(floatingValue * (1 << fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source) : storedValue(source.storedValue)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed	&Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source)
		this->storedValue = source.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	return this->storedValue;
}

void	Fixed::setRawBits(int const rawBits)
{
	this->storedValue = rawBits;
}

int	Fixed::toInt() const
{
	return this->storedValue >> fractionalBits;
}

float	Fixed::toFloat() const
{
	return (float)this->storedValue / (1 << fractionalBits);
}

std::ostream	&operator<<(std::ostream &outputStream, const Fixed &fixedValue)
{
	outputStream << fixedValue.toFloat();
	return outputStream;
}
