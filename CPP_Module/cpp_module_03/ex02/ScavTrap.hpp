#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(ScavTrap const &sourceCopy);
		ScavTrap	&operator=(ScavTrap const &sourceValue);
		~ScavTrap();
		explicit ScavTrap(std::string storedName);

		void	attack(std::string const &targetValue);
		void	guardGate();
};

#endif
