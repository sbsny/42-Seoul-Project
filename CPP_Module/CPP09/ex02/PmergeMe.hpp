#ifndef PMERGEME_HPP
# define PMERGEME_HPP
# include <algorithm>
# include <cstdlib>
# include <ctime>
# include <deque>
# include <iostream>
# include <iterator>
# include <string>
# include <vector>

class PmergeMe
{
	private:
		std::deque<int>		_dequeValues;
		std::vector<int>	_vectorValues;
	public:
		PmergeMe();
		PmergeMe(char **argumentValues);
		PmergeMe(const PmergeMe &source);
		PmergeMe &operator=(const PmergeMe &source);
		~PmergeMe();

		int		digit_check(std::string input);
		void	print_first(std::string label);
		void	sort_print();
};

template <typename T>
void	insertion_sort(T &container)
{
	typename T::iterator	currentIterator = container.begin();

	while (currentIterator != container.end())
	{
		typename T::iterator	scanIterator = currentIterator;

		while (scanIterator != container.begin() && *scanIterator < *(scanIterator - 1))
		{
			std::iter_swap(scanIterator, scanIterator - 1);
			scanIterator--;
		}
		currentIterator++;
	}
}

template <typename T>
void	merge_sort(T &container)
{
	if (container.size() <= 10)
	{
		insertion_sort(container);
		return ;
	}
	typename T::iterator	middleIterator = container.begin() + container.size() / 2;
	T						leftContainer(container.begin(), middleIterator);
	T						rightContainer(middleIterator, container.end());

	merge_sort(leftContainer);
	merge_sort(rightContainer);
	std::merge(leftContainer.begin(), leftContainer.end(), rightContainer.begin(),
		rightContainer.end(), container.begin());
}

#endif
