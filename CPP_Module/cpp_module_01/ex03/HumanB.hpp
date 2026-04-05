

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		Weapon		*weaponStorage;
		std::string	storedName;

	public:
		HumanB(std::string storedName);
		~HumanB();

		void	setWeapon(Weapon &weaponStorage);
		void	attack();
};

#endif
