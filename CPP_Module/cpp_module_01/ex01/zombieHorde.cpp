

#include "Zombie.hpp"

Zombie*	zombieHorde(int countValue, std::string storedName)
{
	if (countValue <= 0)
		return NULL;
	Zombie* zombie = new Zombie[countValue];
	for (int indexValue = 0; indexValue < countValue; indexValue++)
		zombie[indexValue].setName(storedName);
	return zombie;
}
