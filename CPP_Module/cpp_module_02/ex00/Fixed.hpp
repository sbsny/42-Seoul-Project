#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					storedValue;
		static const int	fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &source);
		Fixed	&operator=(const Fixed &source);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const rawBits);
};

#endif
