#include "PmergeMe.hpp"

int	main(int argumentCount, char **argumentValues)
{
	if (argumentCount == 1)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	PmergeMe	sorter(argumentValues);
	return 0;
}
