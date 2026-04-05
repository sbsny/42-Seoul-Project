#include "Harl.hpp"

int	main(int argumentCount, char **argumentValues)
{
	Harl	complainer;

	if (argumentCount == 2)
		complainer.complain(argumentValues[1]);
	else
		std::cout << "Error: Wrong number of arguments" << std::endl;
	return 0;
}
