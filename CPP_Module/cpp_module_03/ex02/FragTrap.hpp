#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(FragTrap const &sourceCopy);
		FragTrap	&operator=(FragTrap const &sourceValue);
		~FragTrap();
		explicit FragTrap(std::string storedName);

		void	attack(std::string const &targetValue);
		void	highFivesGuys();
};

#endif
