#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void printTitle(const std::string &title)
{
	std::cout << "\n===== " << title << " =====" << std::endl;
}

int main()
{
	printTitle("Basic polymorphism");
	const Animal *baseAnimal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << "Type: " << baseAnimal->getType() << std::endl;
	baseAnimal->makeSound();
	std::cout << "Type: " << dog->getType() << std::endl;
	dog->makeSound();
	std::cout << "Type: " << cat->getType() << std::endl;
	cat->makeSound();

	printTitle("Array of Animal pointers");
	const Animal *zoo[4];
	zoo[0] = new Dog();
	zoo[1] = new Cat();
	zoo[2] = new Dog();
	zoo[3] = new Cat();
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "zoo[" << i << "]: " << zoo[i]->getType() << " -> ";
		zoo[i]->makeSound();
	}

	printTitle("Copy and assignment");
	Cat originalCat;
	Cat copiedCat(originalCat);
	Dog firstDog;
	Dog secondDog;
	secondDog = firstDog;
	std::cout << "Copied cat type: " << copiedCat.getType() << std::endl;
	copiedCat.makeSound();
	std::cout << "Assigned dog type: " << secondDog.getType() << std::endl;
	secondDog.makeSound();

	printTitle("WrongAnimal comparison");
	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCatAsAnimal = new WrongCat();
	WrongCat directWrongCat;
	std::cout << "Type: " << wrongAnimal->getType() << std::endl;
	wrongAnimal->makeSound();
	std::cout << "Type: " << wrongCatAsAnimal->getType() << std::endl;
	wrongCatAsAnimal->makeSound();
	std::cout << "Direct WrongCat sound: ";
	directWrongCat.makeSound();

	printTitle("Destruction through base pointers");
	delete baseAnimal;
	delete dog;
	delete cat;
	for (int i = 0; i < 4; ++i)
		delete zoo[i];
	delete wrongAnimal;
	delete wrongCatAsAnimal;
	return 0;
}