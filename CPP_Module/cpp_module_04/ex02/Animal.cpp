#include "Animal.hpp"

Animal::Animal() : storedType("Animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(Animal const &source) : storedType(source.storedType)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &source)
{
	std::cout << "Animal assignment constructor called" << std::endl;
	if (this != &source)
		this->storedType = source.storedType;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string	Animal::getType() const
{
	return this->storedType;
}
