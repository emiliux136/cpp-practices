#include "WrongCat.hpp"

//Orthodox canonical form.

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat: Default constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat: Destructor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal()
{	
	std::cout << "WrongCat: Copy constructor called\n";
	this->type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat: Copy constructor called\n";
	if (this == &other)
    	return *this;
	this->type = other.type;
	return *this;
}

//functions

void WrongCat::makeSound ()
{
	std::cout << "Mamahuevo, digo... miau miau" << std::endl;
}
