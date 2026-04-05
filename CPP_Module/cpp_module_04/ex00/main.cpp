#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << std::endl << "============ TEST1 ============" << std::endl;

	const Animal	*baseAnimal = new Animal();
	const Animal	*dogAnimal = new Dog();
	const Animal	*catAnimal = new Cat();

	std::cout << baseAnimal->getType() << std::endl;
	std::cout << dogAnimal->getType() << std::endl;
	std::cout << catAnimal->getType() << std::endl;

	baseAnimal->makeSound();
	catAnimal->makeSound();
	dogAnimal->makeSound();

	delete baseAnimal;
	delete dogAnimal;
	delete catAnimal;

	std::cout << std::endl << "============ TEST2 ============" << std::endl;

	const WrongAnimal	*wrongBaseAnimal = new WrongAnimal();
	const WrongAnimal	*wrongCatAnimal = new WrongCat();

	std::cout << wrongBaseAnimal->getType() << std::endl;
	std::cout << wrongCatAnimal->getType() << std::endl;

	wrongBaseAnimal->makeSound();
	wrongCatAnimal->makeSound();

	delete wrongBaseAnimal;
	delete wrongCatAnimal;

	return 0;
}
