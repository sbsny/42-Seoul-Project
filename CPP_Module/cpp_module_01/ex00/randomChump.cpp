

#include "Zombie.hpp"

void 	randomChump(std::string storedName)
{
	Zombie zombie;
	zombie.setName(storedName);
	zombie.announce();
}