#include "cat.hpp"

//Orthodox canonical form.

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat: Default constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat: Destructor called\n";
}

Cat::Cat(const Cat &other) : Animal()
{	
	std::cout << "Cat: Copy constructor called\n";
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat: Copy constructor called\n";
	if (this == &other)
    	return *this;
	this->type = other.type;
	return *this;
}

//functions

void Cat::makeSound () const
{
	std::cout << "Mamahuevo, digo... miau miau" << std::endl;
}
