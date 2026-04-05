#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(Cat const &source);
		Cat &operator=(Cat const &source);
		~Cat();

		void	makeSound() const;
};

#endif
