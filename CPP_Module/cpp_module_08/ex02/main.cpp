#include "MutantStack.hpp"

int	main()
{
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator	it = mstack.begin();
	MutantStack<int>::iterator	ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int>	s(mstack);

	std::cout << "============== list ===============" << std::endl;

		std::list<int> list;

		list.push_back(5);
		list.push_back(17);

		std::cout << list.back() << std::endl;

		list.pop_back();

		std::cout << list.size() << std::endl;

		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::list<int>::iterator it3 = list.begin();
		std::list<int>::iterator ite3 = list.end();

		++it3;
		--it3;
		while (it3 != ite3)
		{
			std::cout << *it3 << std::endl;
			++it3;
		}
		std::list<int> s1(list);

	std::cout << "============== A test ===============" << std::endl;

	MutantStack<int>	Astack;

	srand(time(NULL));
	for (int indexValue = 0; indexValue < 10; indexValue++)
		Astack.push(rand() % 100);

	std::cout << "Astack size : " << Astack.size() << std::endl;

	MutantStack<int>::iterator	it2 = Astack.begin();
	MutantStack<int>::iterator	ite2 = Astack.end();

	std::cout << "Astack elements : ";
	while (it2 != ite2)
	{
		std::cout << *it2 << " ";
		it2++;
	}
	std::cout << std::endl;

	for (int indexValue = 0; indexValue < 5; indexValue++)
		Astack.pop();

	std::cout << "============== B test ===============" << std::endl;

	std::cout << "Astack size : " << Astack.size() << std::endl;

	MutantStack<int>::reverse_iterator	rit = Astack.rbegin();
	MutantStack<int>::reverse_iterator	rite = Astack.rend();

	std::cout << "Astack elements : ";
	while (rit != rite)
	{
		std::cout << *rit << " ";
		rit++;
	}
	std::cout << std::endl;

	return 0;
}
