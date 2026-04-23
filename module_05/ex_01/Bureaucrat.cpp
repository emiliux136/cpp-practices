#include "Bureaucrat.hpp"
#include "Form.hpp"

//Orthodox canonical form.

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{}

Bureaucrat::Bureaucrat(std::string const &name, int const &grade) : _name(name)
{
	std::cout << "Bureaucrat: Param constructor called\n";
	checkGrade(grade);
	_grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat: Destructor called\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat: Copy constructor called\n";
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat: Copy assignment operator called\n";
	if (this == &other)
		return *this;
	_grade = other._grade;
	return *this;
}

//ex_00 functions
void Bureaucrat::checkGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

std::string Bureaucrat::getName() const{return this->_name;}

unsigned int Bureaucrat::getGrade() const{return this->_grade;}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}

//ex_01 functions

void Bureaucrat::signForm(const Form *signedForm, const std::string& reason)
{
	if(reason.empty())
		std::cout << this->getName() << " signed " << signedForm->getName() << std::endl;
	else
		std::cout << this->getName() << " couldn" "’" "t sign " << signedForm->getName() << " because " << reason <<std::endl;
}
