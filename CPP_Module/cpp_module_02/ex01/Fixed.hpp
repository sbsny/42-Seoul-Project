#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					storedValue;
		static const int	fractionalBits = 8;

	public:
		Fixed();
		Fixed(int const integerValue);
		Fixed(float const floatingValue);
		Fixed(const Fixed &source);
		Fixed	&operator=(const Fixed &source);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const rawBits);

		int		toInt() const;
		float	toFloat() const;
};

std::ostream	&operator<<(std::ostream &outputStream, const Fixed &fixedValue);

#endif
