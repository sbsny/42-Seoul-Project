#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat constructor called" << std::endl;
	this->storedType = "WrongCat";
}

WrongCat::WrongCat(WrongCat const &source) : WrongAnimal(source)
{
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->storedType = source.storedType;
}

WrongCat &WrongCat::operator=(WrongCat const &source)
{
	std::cout << "Wrongcat copy assignment operator called" << std::endl;
	if (this != &source)
		this->storedType = source.storedType;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "WrongCat sound" << std::endl;
}
