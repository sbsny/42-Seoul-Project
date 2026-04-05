

#include "Weapon.hpp"

Weapon::Weapon(std::string storedType) : storedType(storedType)
{
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType() const
{
	return this->storedType;
}

void	Weapon::setType(std::string storedType)
{
	this->storedType = storedType;
}
