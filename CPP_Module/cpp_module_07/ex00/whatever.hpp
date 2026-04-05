#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void	swap(T &leftValue, T &rightValue)
{
	T	temporaryValue = leftValue;

	leftValue = rightValue;
	rightValue = temporaryValue;
}

template <typename T>
T const	&min(T const &leftValue, T const &rightValue)
{
	if (rightValue < leftValue)
		return rightValue;
	return leftValue;
}

template <typename T>
T const	&max(T const &leftValue, T const &rightValue)
{
	if (leftValue < rightValue)
		return rightValue;
	return leftValue;
}

#endif
