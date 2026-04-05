#include "Dog.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog constructor called" << std::endl;
	this->storedType = "Dog";
}

Dog::Dog(Dog const &source) : Animal(source)
{
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &source)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &source)
		this->storedType = source.storedType;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}
