#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"

int main()
{
	// Uncomment to verify at compile time that Animal is abstract.
	// Animal a;

	const int size = 4;
	Animal *zoo[size];

	for (int i = 0; i < size / 2; i++)
		zoo[i] = new Dog();
	for (int i = size / 2; i < size; i++)
		zoo[i] = new Cat();

	for (int i = 0; i < size; i++)
	{
		std::cout << zoo[i]->getType() << ": ";
		zoo[i]->makeSound();
	}

	for (int i = 0; i < size; i++)
		delete zoo[i];

	return 0;
}