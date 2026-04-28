#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("", 25, 5), target("")
{
	std::cout << "PresidentialPardonForm Default Constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : Form(target, 25, 5), target(target)
{
	std::cout << "PresidentialPardonForm: Param constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : Form(other.target, 25, 5), target(other.target)
{
	std::cout << "PresidentialPardonForm: Copy constructor called'\n";
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardonForm: Copy assignment operator called\n";
	if (this == &other)
		return *this;
	target = other.target;
	this->changeSign(other.getSigned());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() 
{
	std::cout << "PresidentialPardonForm: Destructor called." << std::endl;
}

void PresidentialPardonForm::executer() const
{
	std::cout << "Informs that " << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
