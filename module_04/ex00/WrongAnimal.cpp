#include "WrongAnimal.hpp"

//Orthodox canonical form.

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal: Default constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal: Destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{	
	std::cout << "WrongAnimal: Copy constructor called\n";
	this->type = other.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal: Copy constructor called\n";
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;	
}

//functions

void WrongAnimal::makeSound () const
{
	std::cout << "Generic bipbopbip notanimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}