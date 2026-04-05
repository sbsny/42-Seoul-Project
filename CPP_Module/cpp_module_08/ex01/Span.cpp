#include "Span.hpp"

Span::Span() : n(0), vec() {}

Span::Span(unsigned int n) : n(n), vec() {}

Span::Span(Span const &sourceCopy) : n(sourceCopy.n), vec(sourceCopy.vec)
{
}

Span &Span::operator=(Span const &sourceValue)
{
	if (this != &sourceValue)
	{
		n = sourceValue.n;
		vec = sourceValue.vec;
	}
	return *this;
}

Span::~Span() {}

void	Span::addNumber(int nb)
{
	if (vec.size() == n)
		throw Span::SpanFullException();
	vec.push_back(nb);
}

int		Span::shortestSpan()
{
	if (vec.size() < 2)
		throw Span::SpanEmptyException();
	std::vector<int>	tmp = vec;
	std::sort(tmp.begin(), tmp.end());
	int	min = tmp[1] - tmp[0];
	for (unsigned int indexValue = 2; indexValue < tmp.size(); indexValue++)
	{
		if (tmp[indexValue] - tmp[indexValue - 1] < min)
			min = tmp[indexValue] - tmp[indexValue - 1];
	}
	return min;
}

int		Span::longestSpan()
{
	if (vec.size() < 2)
		throw Span::SpanEmptyException();
	std::vector<int>	tmp = vec;
	std::sort(tmp.begin(), tmp.end());
	int	max = tmp[tmp.size() - 1] - tmp[0];
	return max;
}

const char *Span::SpanFullException::what() const throw()
{
	return ("Span is full");
}

const char *Span::SpanEmptyException::what() const throw()
{
	return ("No space can be found");
}
