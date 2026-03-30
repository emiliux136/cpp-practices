#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
	private:
		std::string const _name;
		unsigned int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const &name, int const &grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		//exception classes
		class GradeTooHighException : public std::exception
		{

		};
		class GradeTooLowException : public std::exception
		{

		};
};

#endif