#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : storedType("WrongAnimal")
{
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &source) : storedType(source.storedType)
{
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &source)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	if (this != &source)
		this->storedType = source.storedType;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return this->storedType;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}
