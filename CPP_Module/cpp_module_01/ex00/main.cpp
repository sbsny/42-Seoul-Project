

#include "Zombie.hpp"

int	main(void) {
	Zombie*	zombie = newZombie("Heap");

	randomChump("Stack");
	zombie->announce();
	delete zombie;
	return (0);
}
