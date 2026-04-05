#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T				*elements;
		unsigned int	elementCount;

	public:
		Array() : elements(new T[0]), elementCount(0)
		{
		}

		Array(unsigned int size) : elements(new T[size]), elementCount(size)
		{
		}

		Array(Array const &source) : elements(NULL), elementCount(0)
		{
			*this = source;
		}

		~Array()
		{
			delete [] elements;
		}

		Array	&operator=(Array const &source)
		{
			if (this == &source)
				return *this;
			delete [] elements;
			elementCount = source.elementCount;
			elements = new T[elementCount];
			for (unsigned int elementIndex = 0; elementIndex < elementCount; elementIndex++)
				elements[elementIndex] = source.elements[elementIndex];
			return *this;
		}

		T	&operator[](unsigned int index)
		{
			if (index >= elementCount)
				throw std::exception();
			return elements[index];
		}

		T const	&operator[](unsigned int index) const
		{
			if (index >= elementCount)
				throw std::exception();
			return elements[index];
		}

		unsigned int	size() const
		{
			return elementCount;
		}
};

template <typename T>
void	printArray(T &arrayValue, std::string arrayName)
{
	std::cout << arrayName << " : ";
	for (unsigned int elementIndex = 0; elementIndex < arrayValue.size(); elementIndex++)
		std::cout << arrayValue[elementIndex] << " ";
	std::cout << std::endl;
}

#endif
