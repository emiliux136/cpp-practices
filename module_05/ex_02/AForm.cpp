#include "AForm.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _sign(false), _signGrade(150), _executionGrade(150)
{
	std::cout << "Form Default Constructor called." << std::endl;
}

Form::Form(std::string const &name, int const &sG, int const &eG) : _name(name)
{
	std::cout << "Form: Param constructor called\n";
	checkGrade(sG);
	checkGrade(eG);
	_signGrade = sG;
	_executionGrade = eG;
	_sign = false;
}
Form::Form(const Form &other) : _name(other._name), _sign(other._sign),_signGrade(other._signGrade), _executionGrade(other._executionGrade)
{
	std::cout << "Form: Copy constructor called\n";
}
Form &Form::operator=(const Form &other)
{
	std::cout << "Bureaucrat: Copy assignment operator called\n";
	if (this == &other)
		return *this;
	_sign = other._sign;
	_signGrade = other._signGrade;
	_executionGrade = other._executionGrade;
	return *this;
}

Form::~Form() 
{ 
	std::cout << "[Form] Destructor called." << std::endl;
}

void Form::checkGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

std::string Form::getName() const
{
	return(this->_name);
}

unsigned int Form::getSignGrade() const
{
	return(this->_signGrade);
}

unsigned int Form::getExectionGrade() const
{
	return(this->_executionGrade);
}

bool Form::getSigned() const
{
	return(this->_sign);
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
	os << "Form '" << obj.getName() << "', signed: "
	   << (obj.getSigned() ? "yes" : "no")
	   << ", sign grade: " << obj.getSignGrade()
	   << ", execution grade: " << obj.getExectionGrade();
	return os;
}

void Form::beSigned(Bureaucrat &signer)
{
	if(this->getSigned())
		std::cout << "This form is already signed." << std::endl;
	else if (this->getSignGrade() < signer.getGrade())
	{
		signer.signForm(this, "grade is too low");
		throw Form::GradeTooLowException();
	}
	else
	{
		signer.signForm(this, "");
		this->_sign = true;
  	}
}

void Form::execute(Bureaucrat const &executor) const
{
	if (!this->getSignGrade())
		throw Form::FormNotSigned();
	if (this->getSignGrade() < executor.getGrade())
		throw Form::GradeTooLowException();
	this->executer();
}

void Form::changeSign(bool newSign)
{
	_sign = newSign;
}