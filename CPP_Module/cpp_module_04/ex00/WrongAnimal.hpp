#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	storedType;

	public:
		WrongAnimal();
		WrongAnimal(WrongAnimal const &source);
		WrongAnimal &operator=(WrongAnimal const &source);
		~WrongAnimal();

		std::string		getType() const;
		void			makeSound() const;
};

#endif
