

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
	private:
		Weapon		&weaponStorage;
		std::string	storedName;

	public:
		HumanA(std::string storedName, Weapon &weaponStorage);
		~HumanA();

		void	attack();
};

#endif
