#include <iostream>
#include <string>
#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern: Constructor called\n";
}

Intern::~Intern()
{
	std::cout << "Intern: Destructor called\n";
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern: Copy constructor called\n";
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern: Copy assignment operator called\n";
	(void)other;
	return(*this);
}

Form *Intern::makeForm(std::string name, std::string target)
{
	std::string FName[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
	int i = 0;
	while (i < 3)
	{
		if (FName[i] == name)
			break;
		i++;
	}

	switch (i)
	{
	case 0:
		{
		std::cout << "Intern creates " << target /* << " as a " << name*/  << std::endl;
		return (new PresidentialPardonForm(target));
		}
	case 1:
		{
		std::cout << "Intern creates " << target /* << " as a " << name */ << std::endl;
		return (new RobotomyRequestForm(target));
		}
	case 2:
		{
		std::cout << "Intern creates " << target /* << " as a " << name */ << std::endl;
		return (new ShrubberyCreationForm(target));
		}
	default:
		throw FormNotFound();
	}
}

const char *Intern::FormNotFound::what() const throw() 
{
  return "Form not found.";
}