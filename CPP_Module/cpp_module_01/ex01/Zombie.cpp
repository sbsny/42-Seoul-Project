

#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie destroyed" << std::endl;
}

void	Zombie::setName(std::string storedName)
{
	this->storedName = storedName;
}

void	Zombie::announce()
{
	std::cout << storedName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
