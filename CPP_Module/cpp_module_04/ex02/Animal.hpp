#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	storedType;

	public:
		Animal();
		Animal(Animal const &source);
		Animal &operator=(Animal const &source);
		virtual ~Animal();

		virtual std::string		getType() const;
		virtual void			makeSound() const = 0;
};

#endif
