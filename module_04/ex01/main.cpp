#include "animal.hpp"
#include "dog.hpp"
#include "cat.hpp"
#include "Brain.hpp"

static void printTitle(const std::string &title)
{
	std::cout << "\n===== " << title << " =====" << std::endl;
}

int main()
{
	printTitle("Testing Brain Ownership");
	
	// Create animals with brains
	Dog* dog1 = new Dog();
	Dog* dog2 = new Dog();
	Cat* cat1 = new Cat();
	
	printTitle("Adding ideas to Dog 1");
	dog1->setIdea("Woof woof!");
	dog1->setIdea("Play fetch!");
	dog1->setIdea("Squirrel!");
	std::cout << "Dog 1 idea: " << dog1->getIdea() << std::endl;
	
	printTitle("Adding ideas to Dog 2");
	dog2->setIdea("Bark bark!");
	dog2->setIdea("Eat treats!");
	std::cout << "Dog 2 idea: " << dog2->getIdea() << std::endl;
	
	printTitle("Adding ideas to Cat 1");
	cat1->setIdea("Meow!");
	cat1->setIdea("Chase mouse!");
	cat1->setIdea("Nap time!");
	std::cout << "Cat 1 idea: " << cat1->getIdea() << std::endl;
	
	printTitle("Verifying separate brains");
	std::cout << "Dog 1 idea again: " << dog1->getIdea() << std::endl;
	std::cout << "Dog 2 idea again: " << dog2->getIdea() << std::endl;
	std::cout << "Cat 1 idea again: " << cat1->getIdea() << std::endl;
	
	// Clean up
	delete dog1;
	delete dog2;
	delete cat1;
	
	printTitle("Test Complete - No Memory Leaks!");


}