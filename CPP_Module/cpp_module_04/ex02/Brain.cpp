#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &source)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = source;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &source)
{
	std::cout << "Brain assignment constructor called" << std::endl;
	if (this == &source)
		return *this;
	for (int ideaIndex = 0; ideaIndex < 100; ideaIndex++)
		this->thoughtStorage[ideaIndex] = source.thoughtStorage[ideaIndex];
	return *this;
}

std::string	Brain::getIdeas(int ideaIndex) const
{
	return this->thoughtStorage[ideaIndex];
}

void	Brain::setIdeas(std::string ideaText, int ideaIndex)
{
	this->thoughtStorage[ideaIndex] = ideaText;
}
