#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	this->storedName = "Default";
	this->healthPointCount = 100;
	this->energyPointCount = 50;
	this->attackDamageValue = 20;
}

ScavTrap::ScavTrap(ScavTrap const &sourceCopy) : ClapTrap(sourceCopy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = sourceCopy;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &sourceValue)
{
	if (this != &sourceValue)
	{
		this->energyPointCount = sourceValue.energyPointCount;
		this->storedName = sourceValue.storedName;
		this->healthPointCount = sourceValue.healthPointCount;
		this->attackDamageValue = sourceValue.attackDamageValue;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string storedName) : ClapTrap(storedName)
{
	std::cout << "ScavTrap string constructor called" << std::endl;
	this->storedName = storedName;
	this->healthPointCount = 100;
	this->energyPointCount = 50;
	this->attackDamageValue = 20;
}

void	ScavTrap::attack(std::string const &targetValue)
{
	if (this->healthPointCount > 0 && this->energyPointCount > 0)
	{
		std::cout << "ScavTrap " << this->storedName << " attacks " << targetValue
		<< ", causing " << this->attackDamageValue << " points of damage" << std::endl;
		this->energyPointCount--;
	}
	else
		std::cout << "ScavTrap " << this->storedName << " can't attack" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->storedName << " is now in Gate keeper mode" << std::endl;
}
