#include <iostream>
#include <map>
#include <utility>

int	main()
{
	std::map<int, char>	numberMap;
	std::map<int, char>::iterator	lowerBoundIterator;

	numberMap.insert(std::make_pair(53, 'A'));
	numberMap.insert(std::make_pair(12, 'Z'));
	numberMap.insert(std::make_pair(33, 'K'));
	numberMap.insert(std::make_pair(66, 'F'));
	for (std::map<int, char>::iterator entryIterator = numberMap.begin();
		entryIterator != numberMap.end(); entryIterator++)
		std::cout << entryIterator->first << " " << entryIterator->second
			<< std::endl;
	lowerBoundIterator = numberMap.lower_bound(54);
	std::cout << "Lower bound is " << lowerBoundIterator->first << " "
		<< lowerBoundIterator->second << std::endl;
	lowerBoundIterator = numberMap.lower_bound(67);
	lowerBoundIterator--;
	std::cout << "Lower bound is  " << lowerBoundIterator->first << " "
		<< lowerBoundIterator->second << std::endl;
	lowerBoundIterator = numberMap.lower_bound(66);
	std::cout << "Lower bound is  " << lowerBoundIterator->first << " "
		<< lowerBoundIterator->second << std::endl;
	return 0;
}
