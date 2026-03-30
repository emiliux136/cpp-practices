#include "Bureaucrat.hpp"

//Orthodox canonical form.

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : _name(name)
{
	std::cout << "Bureaucrat: Default constructor called\n";
	if(grade > 150)
		throw
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{	
	std::cout << "Bureaucrat: Copy constructor called\n";
	*this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat: Copy constructor called\n";
	if (this == &other)
    	return *this;
	return *this;
}

//functions