#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		unsigned int	attackDamageValue;
		unsigned int	energyPointCount;
		unsigned int	healthPointCount;
		std::string		storedName;

	public:
		ClapTrap();
		ClapTrap(ClapTrap const &sourceCopy);
		ClapTrap	&operator=(ClapTrap const &sourceValue);
		~ClapTrap();
		explicit ClapTrap(std::string storedName);

		void	attack(std::string const &targetValue);
		void	takeDamage(unsigned int amountValue);
		void	beRepaired(unsigned int amountValue);

		std::string		getName() const;
		unsigned int	getHealthPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;
};

std::ostream	&operator<<(std::ostream &outputStream, ClapTrap const &sourceValue);

#endif
