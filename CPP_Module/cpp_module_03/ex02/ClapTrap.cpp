#include "ClapTrap.hpp"

static bool	canUseAction(const ClapTrap &trap)
{
	return (trap.getHealthPoints() > 0 && trap.getEnergyPoints() > 0);
}

static unsigned int	clampDamage(unsigned int amountValue, unsigned int currentHp)
{
	if (amountValue > currentHp)
		return currentHp;
	return amountValue;
}

ClapTrap::ClapTrap()
	: attackDamageValue(0), energyPointCount(10), healthPointCount(10), storedName("Default")
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &sourceCopy)
	: attackDamageValue(sourceCopy.attackDamageValue), energyPointCount(sourceCopy.energyPointCount),
	healthPointCount(sourceCopy.healthPointCount), storedName(sourceCopy.storedName)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &sourceValue)
{
	if (this != &sourceValue)
	{
		this->attackDamageValue = sourceValue.attackDamageValue;
		this->energyPointCount = sourceValue.energyPointCount;
		this->healthPointCount = sourceValue.healthPointCount;
		this->storedName = sourceValue.storedName;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string const storedName)
	: attackDamageValue(0), energyPointCount(10), healthPointCount(10), storedName(storedName)
{
	std::cout << "ClapTrap string constructor called" << std::endl;
}

void	ClapTrap::attack(std::string const &targetValue)
{
	if (!canUseAction(*this))
	{
		std::cout << "ClapTrap " << this->storedName << " can't attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->storedName << " attacks " << targetValue
		<< ", causing " << this->attackDamageValue << " points of damage" << std::endl;
	this->energyPointCount--;
}

void	ClapTrap::takeDamage(unsigned int amountValue)
{
	if (this->healthPointCount == 0)
	{
		std::cout << "ClapTrap " << this->storedName << " can't take damage" << std::endl;
		return ;
	}
	amountValue = clampDamage(amountValue, this->healthPointCount);
	std::cout << "ClapTrap " << this->storedName << " takes " << amountValue
		<< " points of damage" << std::endl;
	this->healthPointCount -= amountValue;
}

void	ClapTrap::beRepaired(unsigned int amountValue)
{
	if (!canUseAction(*this))
	{
		std::cout << "ClapTrap " << this->storedName << " can't be repaired" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->storedName << " is repaired by "
		<< amountValue << " points" << std::endl;
	this->healthPointCount += amountValue;
	this->energyPointCount--;
}

std::string	ClapTrap::getName() const
{
	return this->storedName;
}

unsigned int	ClapTrap::getHealthPoints() const
{
	return this->healthPointCount;
}

unsigned int	ClapTrap::getEnergyPoints() const
{
	return this->energyPointCount;
}

unsigned int	ClapTrap::getAttackDamage() const
{
	return this->attackDamageValue;
}

std::ostream	&operator<<(std::ostream &outputStream, ClapTrap const &sourceValue)
{
	outputStream << "Name        : " << sourceValue.getName() << std::endl;
	outputStream << "HealthPoints: " << sourceValue.getHealthPoints() << std::endl;
	outputStream << "EnergyPoints: " << sourceValue.getEnergyPoints() << std::endl;
	outputStream << "AttackDamage: " << sourceValue.getAttackDamage() << std::endl;
	return outputStream;
}
