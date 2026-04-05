

#include "Zombie.hpp"

Zombie*	newZombie(std::string storedName)
{
	Zombie* zombie = new Zombie;
	zombie->setName(storedName);
	return (zombie);
}
