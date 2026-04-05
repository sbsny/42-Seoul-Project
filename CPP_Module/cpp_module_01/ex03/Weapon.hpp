

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	storedType;

	public:
		Weapon(std::string storedType);
		~Weapon();

		const std::string	&getType() const;
		void				setType(std::string storedType);
};

#endif
