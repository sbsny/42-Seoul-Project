#include "Fixed.hpp"

Fixed::Fixed() : storedValue(0)
{
}

Fixed::Fixed(int const integerValue) : storedValue(integerValue << fractionalBits)
{
}

Fixed::Fixed(float const floatingValue)
	: storedValue(roundf(floatingValue * (1 << fractionalBits)))
{
}

Fixed::Fixed(const Fixed &source) : storedValue(source.storedValue)
{
}

Fixed	&Fixed::operator=(const Fixed &source)
{
	if (this != &source)
		this->storedValue = source.storedValue;
	return *this;
}

Fixed::~Fixed()
{
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

bool	Fixed::operator>(const Fixed &other) const
{
	return this->storedValue > other.storedValue;
}

bool	Fixed::operator<(const Fixed &other) const
{
	return this->storedValue < other.storedValue;
}

bool	Fixed::operator>=(const Fixed &other) const
{
	return this->storedValue >= other.storedValue;
}

bool	Fixed::operator<=(const Fixed &other) const
{
	return this->storedValue <= other.storedValue;
}

bool	Fixed::operator==(const Fixed &other) const
{
	return this->storedValue == other.storedValue;
}

bool	Fixed::operator!=(const Fixed &other) const
{
	return this->storedValue != other.storedValue;
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed	&Fixed::operator++()
{
	this->storedValue++;
	return *this;
}

Fixed	Fixed::operator++(int)
{
	Fixed	previousValue(*this);
	this->storedValue++;
	return previousValue;
}

Fixed	&Fixed::operator--()
{
	this->storedValue--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed	previousValue(*this);
	this->storedValue--;
	return previousValue;
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	return a < b ? a : b;
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	return a > b ? a : b;
}

std::ostream	&operator<<(std::ostream &outputStream, const Fixed &fixedValue)
{
	outputStream << fixedValue.toFloat();
	return outputStream;
}
