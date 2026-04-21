#include "Bureaucrat.hpp"

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

//functions

//función para centralizar la comprobación de grado.
void Bureaucrat::checkGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

// Funcion de incrementacion
void Bureaucrat::incrementGrade() {
    if (_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

// Funcion de decrementacion
void Bureaucrat::decrementGrade() {
    if (_grade >= 150)
        throw GradeTooLowException();
    _grade++;
}

std::string Bureaucrat::getName() const{return this->_name;}

unsigned int Bureaucrat::getGrade() const{return this->_grade;}

// os es una referencia a un flujo de salida de tipo std::ostream.
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
	os << obj.getName() << ", bureucrat grade " << obj.getGrade() << "." << std::endl;
	return os;
}