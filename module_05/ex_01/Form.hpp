#ifndef FORM_HPP
#define FORM_HPP

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
		Form(std::string const &name, bool &sign, int const &sG, int const &eG);
		Form(const Form &other);
		Form &operator=(const Form &other);

		void checkGrade(int grade);
		std::string getName() const;
		bool getSigned() const;
		unsigned int getSignGrade() const;
		unsigned int getExectionGrade() const;
		
		void beSigned(Bureaucrat &Signer);

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

std::ostream &operator<<(std::ostream &os, const Form &obj);

#endif