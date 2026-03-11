#include "dog.hpp"

//Orthodox canonical form.

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->DogBrain = new Brain();
	std::cout << "Dog: Default constructor called\n";
}

Dog::~Dog()
{
	delete this->DogBrain;
	std::cout << "Dog: Destructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{	
	std::cout << "Dog: Copy constructor called\n";
	delete this->DogBrain;
	this->DogBrain = new Brain(*other.DogBrain);
	this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog: Copy constructor called\n";
	if (this == &other)
    	return *this;
	this->type = other.type;
	delete this->DogBrain;
	this->DogBrain = new Brain(*other.DogBrain);
	return *this;
}

//functions

void Dog::makeSound () const
{
	std::cout << "GUAU GUAU GUAU" << std::endl;
}

void Dog::setIdea(std::string think)
{
	this->DogBrain->setIdea(think);
}

std::string Dog::getIdea(void)
{
	return this->DogBrain->getIdea();
}