#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(WrongCat const &source);
		WrongCat &operator=(WrongCat const &source);
		~WrongCat();

		void	makeSound() const;
};

#endif
