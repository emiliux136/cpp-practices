#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("", 72, 45), target("")
{
	std::cout << "RobotomyRequestForm Default Constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : Form(target, 72, 45), target(target)
{
	std::cout << "RobotomyRequestForm: Param constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Form(other.target, 72, 45), target(other.target)
{
	std::cout << "RobotomyRequestForm: Copy constructor called'\n";
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm: Copy assignment operator called\n";
	if (this == &other)
		return *this;
	target = other.target;
	this->changeSign(other.getSigned());
}

RobotomyRequestForm::~RobotomyRequestForm() 
{
	std::cout << "RobotomyRequestForm: Destructor called." << std::endl;
}

void RobotomyRequestForm::executer() const
{
    bool result = rand() % 2 == 0; //con esto consigo la aleatoriedad del 50 porciento.
    std::cout << "BzzzZ Drzzzz (Drilling noises)" << std::endl;
    if(result)
	    std::cout << "Informs that " << this->target << " has been robotomized successfully" << std::endl;
    else
 	    std::cout << "Informs that " << this->target << " robotomization failed :(" << std::endl;       
}

