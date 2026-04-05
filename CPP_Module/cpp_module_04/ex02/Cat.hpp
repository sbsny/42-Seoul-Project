#include "Animal.hpp"
#include "Brain.hpp"

#ifndef CAT_HPP
# define CAT_HPP

class Cat : public Animal
{
	private:
		Brain	*brainStorage;

	public:
		Cat();
		Cat(const Cat &source);
		~Cat();
		Cat& 		operator=(const Cat &source);
		std::string	getType() const;
		void 		makeSound() const;
		void		getIdeas(int ideaIndex) const;
		void		setIdeas(std::string ideaText, int ideaIndex);
};

#endif
