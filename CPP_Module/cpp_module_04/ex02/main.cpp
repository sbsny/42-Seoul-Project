#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << std::endl << "SUBJECT TEST :" << std::endl << std::endl;
	const Animal	*dogAnimal = new Dog();
	const Animal	*catAnimal = new Cat();

	delete dogAnimal;
	delete catAnimal;

	std::cout << std::endl << "ARRAY TEST :" << std::endl << std::endl;
	Animal	*animalArray[4];
	const int	animalCount = 4;

	for (int animalIndex = 0; animalIndex < animalCount; animalIndex++)
	{
		if (animalIndex < animalCount / 2)
			animalArray[animalIndex] = new Dog();
		else
			animalArray[animalIndex] = new Cat();
	}
	std::cout << std::endl;
	for (int animalIndex = 0; animalIndex < animalCount; animalIndex++)
		animalArray[animalIndex]->makeSound();
	std::cout << std::endl;
	for (int animalIndex = 0; animalIndex < animalCount; animalIndex++)
		delete animalArray[animalIndex];

	std::cout << std::endl << "COPY TEST :" << std::endl << std::endl;
	Dog	originalDog;
	originalDog.setIdeas("test1", 0);

	Dog	copiedDog(originalDog);
	std::cout << std::endl;
	originalDog.getIdeas(0);
	copiedDog.getIdeas(0);

	std::cout << std::endl;
	originalDog.setIdeas("test2", 0);
	originalDog.getIdeas(0);
	copiedDog.getIdeas(0);
	std::cout << std::endl;

	return 0;
}
