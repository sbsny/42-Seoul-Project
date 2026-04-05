#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat() : Animal()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->storedType = "Cat";
	this->brainStorage = new Brain();
}

Cat::Cat(const Cat &source) : Animal(source)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brainStorage = new Brain();
	*this = source;
}

Cat::~Cat()
{
	delete this->brainStorage;
	std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &source)
{
	std::cout << "Cat assignment constructor called" << std::endl;
	if (this == &source)
		return *this;
	this->storedType = source.storedType;
	*this->brainStorage = *source.brainStorage;
	return *this;
}

void	Cat::makeSound() const
{
	std::cout << "Cat sound" << std::endl;
}

std::string	Cat::getType() const
{
	return this->storedType;
}

void	Cat::getIdeas(int ideaIndex) const
{
	std::cout << this->brainStorage->getIdeas(ideaIndex) << std::endl;
}

void	Cat::setIdeas(std::string ideaText, int ideaIndex)
{
	if (ideaIndex < 0 || ideaIndex >= 100)
		return ;
	this->brainStorage->setIdeas(ideaText, ideaIndex);
}
