

#include "HumanA.hpp"

HumanA::HumanA(std::string storedName, Weapon &weaponStorage) : weaponStorage(weaponStorage), storedName(storedName)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack()
{
	std::cout << storedName << " attacks with their " << weaponStorage.getType() << std::endl;
}
