#include "Dog.hpp"
#include "Animal.hpp"

Dog::Dog() : Animal()
{
	std::cout << "Dog default constructor called" << std::endl;
	this->storedType = "Dog";
	this->brainStorage = new Brain();
}

Dog::Dog(const Dog &source) : Animal(source)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brainStorage = new Brain();
	*this = source;
}

Dog::~Dog()
{
	delete this->brainStorage;
	std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &source)
{
	std::cout << "Dog assignment constructor called" << std::endl;
	if (this == &source)
		return *this;
	this->storedType = source.storedType;
	*this->brainStorage = *source.brainStorage;
	return *this;
}

void	Dog::makeSound() const
{
	std::cout << "Dog sound" << std::endl;
}

std::string	Dog::getType() const
{
	return this->storedType;
}

void	Dog::getIdeas(int ideaIndex) const
{
	std::cout << this->brainStorage->getIdeas(ideaIndex) << std::endl;
}

void	Dog::setIdeas(std::string ideaText, int ideaIndex)
{
	if (ideaIndex < 0 || ideaIndex >= 100)
		return ;
	this->brainStorage->setIdeas(ideaText, ideaIndex);
}
