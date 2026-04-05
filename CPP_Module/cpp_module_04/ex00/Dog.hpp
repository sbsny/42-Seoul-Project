#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(Dog const &source);
		Dog &operator=(Dog const &source);
		~Dog();

		void	makeSound() const;
};

#endif
