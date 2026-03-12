#include "animal.hpp"

//Orthodox canonical form.

Animal::Animal()
{
	std::cout << "Animal: Default constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal: Destructor called\n";
}

Animal::Animal(const Animal &other)
{	
	std::cout << "Animal: Copy constructor called\n";
	this->type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal: Copy constructor called\n";
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;	
}

//functions

void Animal::makeSound () const
{
	std::cout << "Generic animal theoretical sound" << std::endl;
}

void Animal::setIdea(const std::string &think) const
{
	(void)think;
}

std::string Animal::getIdea() const
{
	return "";
}

std::string Animal::getType() const
{
	return type;
}