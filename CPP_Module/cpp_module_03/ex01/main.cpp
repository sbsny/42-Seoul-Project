#include "ScavTrap.hpp"

int	main()
{
	ScavTrap	firstTrap("Num1");

	std::cout << std::endl << firstTrap << std::endl;

	firstTrap.guardGate();
	firstTrap.attack("enemy");
	firstTrap.beRepaired(50);
	firstTrap.takeDamage(150);

	std::cout << std::endl << firstTrap << std::endl;

	ScavTrap	secondTrap("Num2");
	ClapTrap	*baseView = &secondTrap;

	secondTrap.attack("enemy");
	baseView->attack("enemy");

	return 0;
}
