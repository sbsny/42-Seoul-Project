#include "Animal.hpp"
#include "Brain.hpp"

#ifndef DOG_HPP
# define DOG_HPP

class Dog : public Animal
{
	private:
		Brain	*brainStorage;

	public:
		Dog();
		Dog(const Dog &source);
		~Dog();
		Dog&		operator=(const Dog &source);
		std::string	getType() const;
		void		makeSound() const;
		void		getIdeas(int ideaIndex) const;
		void		setIdeas(std::string ideaText, int ideaIndex);
};

#endif
