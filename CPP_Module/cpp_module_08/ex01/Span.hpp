#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

class Span
{
	private:
		unsigned int		n;
		std::vector<int>	vec;

	public:
		Span();
		Span(Span const &sourceCopy);
		Span &operator=(Span const &sourceValue);
		~Span();
		explicit Span(unsigned int n);

		void	addNumber(int nb);
		int		shortestSpan();
		int		longestSpan();

		class SpanFullException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class SpanEmptyException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		template <typename Iter>
		void	addNumber(Iter begin, Iter end)
		{
			if (vec.size() + end - begin > n)
				throw SpanFullException();
			vec.insert(vec.begin(), begin, end);
		}
};

#endif
