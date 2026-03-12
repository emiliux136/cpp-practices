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
	this->DogBrain = new Brain(*other.DogBrain);
	this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog: Copy assignment operator called\n";
	if (this == &other)
    	return *this;
	Animal::operator=(other);
	delete this->DogBrain;
	this->DogBrain = new Brain(*other.DogBrain);
	return *this;
}

//functions

void Dog::makeSound () const
{
	std::cout << "GUAU GUAU GUAU" << std::endl;
}

void Dog::setIdea(const std::string &think) const
{
	this->DogBrain->setIdea(think);
}

std::string Dog::getIdea() const
{
	return this->DogBrain->getIdea();
}