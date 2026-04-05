

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string	storedName;

	public:
		Zombie();
		~Zombie();

		void	setName(std::string storedName);
		void	announce();
};

Zombie*	newZombie(std::string storedName);
void	randomChump(std::string storedName);

#endif
