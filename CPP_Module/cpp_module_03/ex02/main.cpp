#include "FragTrap.hpp"

int	main()
{
	FragTrap	firstTrap("Num1");

	std::cout << std::endl << firstTrap << std::endl;

	firstTrap.highFivesGuys();
	firstTrap.attack("enemy");
	firstTrap.beRepaired(50);
	firstTrap.takeDamage(150);

	std::cout << std::endl << firstTrap << std::endl;

	FragTrap	secondTrap("Num2");
	ClapTrap	*baseView = &secondTrap;

	secondTrap.attack("enemy");
	baseView->attack("enemy");

	return 0;
}
