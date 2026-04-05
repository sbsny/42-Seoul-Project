

#include <iostream>

int	main(int argumentCount, char **argumentValues)
{
	if (argumentCount == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		std::string stringValue;
		for (int indexValue = 1; indexValue < argumentCount; indexValue++)
		{
			stringValue = argumentValues[indexValue];
			for (int indexValueTwo = 0; stringValue[indexValueTwo]; indexValueTwo++)
				std::cout << (char)toupper(stringValue[indexValueTwo]);
		}
	}
	std::cout << std::endl;
	return 0;
}
