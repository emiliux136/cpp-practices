#include "cat.hpp"

//Orthodox canonical form.

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->catBrain = new Brain();
	std::cout << "Cat: Default constructor called\n";
}

Cat::~Cat()
{
	delete this->catBrain;
	std::cout << "Cat: Destructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{	
	std::cout << "Cat: Copy constructor called\n";
	this->catBrain = new Brain(*other.catBrain);
	this->type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat: Copy assignment operator called\n";
	if (this == &other)
    	return *this;
	Animal::operator=(other);
	delete this->catBrain;
	this->catBrain = new Brain(*other.catBrain);
	return *this;
}

//functions

void Cat::makeSound () const
{
	std::cout << "miau, miau, miau" << std::endl;
}

void Cat::setIdea(const std::string &think) const
{
	this->catBrain->setIdea(think);
}

std::string Cat::getIdea() const
{
	return this->catBrain->getIdea();
}
