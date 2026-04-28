#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _sign;
		unsigned int _signGrade;
		unsigned int _executionGrade;
	public:
		Form();
		Form(std::string const &name, int const &sG, int const &eG);
		Form(const Form &other);
		~Form();
		Form &operator=(const Form &other);

		void checkGrade(int grade);
		std::string getName() const;
		bool getSigned() const;
		unsigned int getSignGrade() const;
		unsigned int getExectionGrade() const;
		void beSigned(Bureaucrat &Signer);

		void changeSign(bool newSign);
		void execute(Bureaucrat const &executor) const;
		virtual void executer() const = 0;
		// abstact function redefined in each son.

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
		class FormNotSigned : public std::exception
		{
			public:
			const char* what() const noexcept override 
			{
				return "Form is not signed";
			}
		};
};

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif