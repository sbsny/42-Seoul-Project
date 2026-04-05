#include "Cat.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat constructor called" << std::endl;
	this->storedType = "Cat";
}

Cat::Cat(Cat const &source) : Animal(source)
{
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &source)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &source)
		this->storedType = source.storedType;
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}
