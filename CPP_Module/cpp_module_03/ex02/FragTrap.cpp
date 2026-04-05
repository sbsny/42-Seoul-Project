#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->storedName = "Default";
	this->healthPointCount = 100;
	this->energyPointCount = 100;
	this->attackDamageValue = 30;
}

FragTrap::FragTrap(FragTrap const &sourceCopy) : ClapTrap(sourceCopy)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = sourceCopy;
}

FragTrap	&FragTrap::operator=(FragTrap const &sourceValue)
{
	if (this != &sourceValue)
	{
		this->healthPointCount = sourceValue.healthPointCount;
		this->attackDamageValue = sourceValue.attackDamageValue;
		this->storedName = sourceValue.storedName;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::FragTrap(std::string storedName) : ClapTrap(storedName)
{
	std::cout << "FragTrap string constructor called" << std::endl;
	this->storedName = storedName;
	this->healthPointCount = 100;
	this->energyPointCount = 100;
	this->attackDamageValue = 30;
}

void	FragTrap::attack(std::string const &targetValue)
{
	if (this->healthPointCount > 0 && this->energyPointCount > 0)
	{
		std::cout << "FragTrap " << this->storedName << " attacks " << targetValue
		<< ", causing " << this->attackDamageValue << " points of damage" << std::endl;
		this->energyPointCount--;
	}
	else
		std::cout << "FragTrap " << this->storedName << " can't attack" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->storedName << " gives high fives" << std::endl;
}
