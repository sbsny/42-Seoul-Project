#include "RPN.hpp"

int main(int argumentCount, char **argumentValues)
{
	if (argumentCount != 2)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}
	RPN	calculator(argumentValues[1]);
	return 0;
}
