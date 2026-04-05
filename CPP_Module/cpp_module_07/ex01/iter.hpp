#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void	iter(T *arrayStorage, int length, void (*apply)(T&))
{
	for (int elementIndex = 0; elementIndex < length; elementIndex++)
		apply(arrayStorage[elementIndex]);
}

template <typename T>
void	print(T &storedValue)
{
	std::cout << storedValue << std::endl;
}

#endif
