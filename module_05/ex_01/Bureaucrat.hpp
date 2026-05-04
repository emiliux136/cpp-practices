#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;

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

		void checkGrade(int grade);
		void incrementGrade();
		void decrementGrade();
		std::string getName() const;
		unsigned int getGrade() const;

		void signForm(const Form *signedForm, const std::string& reason);

		class GradeTooHighException : public std::exception
		{
			public:
			const char* what() const noexcept override 
			{
				return "Grade too high";
			}
		};
		class GradeTooLowException : public std::exception
		{
			public:
			const char* what() const noexcept override 
			{
				return "Grade too low";
			}
		};
};

// << declared outside the class because the left-hand operand is std::ostream not the class type
std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif