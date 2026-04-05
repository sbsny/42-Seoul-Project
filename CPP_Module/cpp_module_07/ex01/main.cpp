#include "iter.hpp"

int	main()
{
	std::cout << "========== TEST1 ==========" << std::endl;
	int integerArray[] = {1, 2, 3, 4, 5};
	iter(integerArray, 5, print);

	std::cout << "========== TEST2 ==========" << std::endl;
	double	doubleArray[] = {0.0, 0.1, 0.2, 0.3, 0.4};
	iter(doubleArray, 5, print);

	std::cout << "========== TEST3 ==========" << std::endl;
	std::string	stringArray[] = {"test1", "test2", "test3"};
	iter(stringArray, 3, print);

	return 0;
}
