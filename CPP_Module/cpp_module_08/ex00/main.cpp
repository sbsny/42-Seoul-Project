#include "easyfind.hpp"

int	main()
{
	std::vector<int>	vectorValues;
	std::deque<int>	dequeValues;

	vectorValues.push_back(5);
	vectorValues.push_back(7);
	vectorValues.push_back(42);

	dequeValues.push_back(5);
	dequeValues.push_back(7);
	dequeValues.push_back(42);

	try
	{
		std::cout << "======= vector =======" << std::endl;
		std::cout << *easyfind(vectorValues, 5) << std::endl;
		std::cout << *easyfind(vectorValues, 7) << std::endl;
		std::cout << *easyfind(vectorValues, 10) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "======= deque =======" << std::endl;
		std::cout << *easyfind(dequeValues, 5) << std::endl;
		std::cout << *easyfind(dequeValues, 7) << std::endl;
		std::cout << *easyfind(dequeValues, 10) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
