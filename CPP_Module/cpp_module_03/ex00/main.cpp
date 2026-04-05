#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	firstTrap("Num1");

	std::cout << std::endl << firstTrap << std::endl;

	firstTrap.attack("enemy");
	firstTrap.beRepaired(5);
	firstTrap.takeDamage(20);

	std::cout << std::endl << firstTrap << std::endl;

	firstTrap.attack("enemy");
	firstTrap.beRepaired(10);
	firstTrap.takeDamage(5);
	std::cout << std::endl;

	return 0;
}
