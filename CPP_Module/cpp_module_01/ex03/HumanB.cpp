

#include "HumanB.hpp"

HumanB::HumanB(std::string storedName) : weaponStorage(NULL), storedName(storedName)
{
}

HumanB::~HumanB()
{
}

void HumanB::setWeapon(Weapon &weaponStorage)
{
	this->weaponStorage = &weaponStorage;
}

void	HumanB::attack()
{
	if (weaponStorage)
		std::cout << storedName << " attacks with their " << weaponStorage->getType() << std::endl;
}
