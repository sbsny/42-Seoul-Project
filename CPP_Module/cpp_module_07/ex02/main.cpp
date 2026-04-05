#include "Array.hpp"

int	main()
{
	Array<int>	numberArray(5);
	srand(time(NULL));

	for (unsigned int index = 0; index < numberArray.size(); index++)
		numberArray[index] = index + rand() % 10;

	Array<int>	copiedArray(numberArray);

	printArray(numberArray, "a");
	printArray(copiedArray, "b");
	std::cout << std::endl;

	for (unsigned int index = 0; index < copiedArray.size(); index++)
		copiedArray[index] = index;

	printArray(numberArray, "a");
	printArray(copiedArray, "b");
	std::cout << std::endl;

	const Array<int>	readOnlyArray(5);
	std::cout << readOnlyArray[0] << std::endl;

	try
	{
		numberArray[6] = 42;
		std::cout << numberArray[6] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Index is out of range" << std::endl;
	}

	try
	{
		copiedArray[-5] = 42;
		std::cout << copiedArray[-5] << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Index is out of range" << std::endl;
	}

	return 0;
}
