#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

static void	seedRandom()
{
	static bool	isRandomSeeded = false;

	if (!isRandomSeeded)
	{
		std::srand(static_cast<unsigned int>(time(NULL)));
		isRandomSeeded = true;
	}
}

Base	*generate()
{
	int	randomIndex;

	seedRandom();
	randomIndex = std::rand() % 3;
	if (randomIndex == 0)
		return new A;
	if (randomIndex == 1)
		return new B;
	return new C;
}

void	identify(Base *basePtr)
{
	if (dynamic_cast<A*>(basePtr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(basePtr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(basePtr))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void	identify(Base &baseRef)
{
	try
	{
		dynamic_cast<A&>(baseRef);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception&)
	{
	}
	try
	{
		dynamic_cast<B&>(baseRef);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception&)
	{
	}
	try
	{
		dynamic_cast<C&>(baseRef);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception&)
	{
	}
	std::cout << "Error" << std::endl;
}

int main()
{
	Base	*generatedBase = generate();

	identify(generatedBase);
	identify(*generatedBase);

	delete generatedBase;

	return 0;
}
