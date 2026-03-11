#include "dog.hpp"

//Orthodox canonical form.

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog: Default constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog: Destructor called\n";
}

Dog::Dog(const Dog &other) : Animal()
{	
	std::cout << "Dog: Copy constructor called\n";
	this->type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog: Copy constructor called\n";
	if (this == &other)
    	return *this;
	this->type = other.type;
	return *this;
}

//functions

void Dog::makeSound () const
{
	std::cout << "GUAU GUAU GUAU" << std::endl;
}
