#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _dequeValues(), _vectorValues()
{
}

PmergeMe::PmergeMe(char **argumentValues) : _dequeValues(), _vectorValues()
{
	for (int argumentIndex = 1; argumentValues[argumentIndex] != NULL; argumentIndex++)
	{
		int	parsedValue;

		digit_check(argumentValues[argumentIndex]);
		parsedValue = std::atoi(argumentValues[argumentIndex]);
		this->_dequeValues.push_back(parsedValue);
		this->_vectorValues.push_back(parsedValue);
	}
	sort_print();
}

PmergeMe::PmergeMe(const PmergeMe &source)
	: _dequeValues(source._dequeValues), _vectorValues(source._vectorValues)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &source)
{
	if (this != &source)
	{
		this->_dequeValues = source._dequeValues;
		this->_vectorValues = source._vectorValues;
	}
	return *this;
}

PmergeMe::~PmergeMe()
{
}

int	PmergeMe::digit_check(std::string input)
{
	for (std::size_t characterIndex = 0; characterIndex < input.size(); characterIndex++)
	{
		if (!std::isdigit(input[characterIndex]))
		{
			std::cout << "Error" << std::endl;
			std::exit(1);
		}
	}
	return 1;
}

void	PmergeMe::print_first(std::string label)
{
	std::cout << label << ": ";
	for (std::size_t valueIndex = 0; valueIndex < this->_dequeValues.size()
		&& valueIndex < 4; valueIndex++)
		std::cout << this->_dequeValues[valueIndex] << " ";
	if (this->_dequeValues.size() == 5)
		std::cout << this->_dequeValues[4];
	else if (this->_dequeValues.size() > 5)
		std::cout << "[...]";
	std::cout << std::endl;
}

void	PmergeMe::sort_print()
{
	clock_t	startClock;
	clock_t	endClock;
	double	elapsedMicroseconds;

	print_first("Before sort");
	startClock = clock();
	merge_sort(this->_dequeValues);
	this->_dequeValues.erase(std::unique(this->_dequeValues.begin(),
			this->_dequeValues.end()), this->_dequeValues.end());
	endClock = clock();
	elapsedMicroseconds = static_cast<double>(endClock - startClock)
		/ CLOCKS_PER_SEC * 1000000.0;
	print_first("After sort");
	std::cout << "Time to process with std::deque: " << elapsedMicroseconds
		<< " microseconds" << std::endl;
	startClock = clock();
	merge_sort(this->_vectorValues);
	this->_vectorValues.erase(std::unique(this->_vectorValues.begin(),
			this->_vectorValues.end()), this->_vectorValues.end());
	endClock = clock();
	elapsedMicroseconds = static_cast<double>(endClock - startClock)
		/ CLOCKS_PER_SEC * 1000000.0;
	std::cout << "Time to process with std::vector: " << elapsedMicroseconds
		<< " microseconds" << std::endl;
}
