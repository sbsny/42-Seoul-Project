

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

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

Zombie*	zombieHorde(int countValue, std::string storedName);

#endif
