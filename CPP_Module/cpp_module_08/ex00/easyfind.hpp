#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <exception>

class NotFoundException : public std::exception
{
	public:
		const char	*what() const throw()
		{
			return "Element not found";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int targetValue)
{
	typename T::iterator	foundIterator;

	foundIterator = std::find(container.begin(), container.end(), targetValue);
	if (foundIterator == container.end())
		throw NotFoundException();
	return foundIterator;
}

#endif
