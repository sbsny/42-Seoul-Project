

#include "Zombie.hpp"

int	main(int argumentCount, char **argumentValues)
{
	if (argumentCount == 3)
	{
		int	countValue = atoi(argumentValues[1]);
		if (countValue > 0)
		{
			std::string	storedName = argumentValues[2];
			Zombie* zombie = zombieHorde(countValue, storedName);
			for (int indexValue = 0; indexValue < countValue; indexValue++)
				zombie[indexValue].announce();
			delete[] zombie;
		}
		else
			std::cout << "Error: Wrong number of zombies" << std::endl;
	}
	else
		std::cout << "Error: Wrong number of arguments" << std::endl;
	return 0;
}
