#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

static void printTitle(const std::string &title)
{
	std::cout << "\n========== " << title << " ==========" << std::endl;
}

static void trySignAndExecute(Form &form, Bureaucrat &signer, Bureaucrat &executor)
{
	std::cout << "Before sign: " << form << std::endl;
	try
	{
		form.beSigned(signer);
		std::cout << "After sign:  " << form << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Sign failed: " << e.what() << std::endl;
	}

	try
	{
		form.execute(executor);
	}
	catch (const std::exception &e)
	{
		std::cout << "Execute failed: " << e.what() << std::endl;
	}
}

int main()
{
	std::srand(std::time(NULL));

	printTitle("Bureaucrat boundaries");
	
	try
	{
		Bureaucrat defaultBureaucrat;
		Bureaucrat top("Top", 1);
		Bureaucrat bottom("Bottom", 150);
		std::cout << defaultBureaucrat;
		std::cout << top;
		std::cout << bottom;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("Form construction and signing");
	try
	{
		Bureaucrat intern("Intern", 140);
		Bureaucrat manager("Manager", 40);
		Bureaucrat president("President", 1);

		ShrubberyCreationForm shrubbery("home");
		RobotomyRequestForm robotomy("Bender");
		PresidentialPardonForm pardon("Arthur Dent");

		trySignAndExecute(shrubbery, intern, intern);
		trySignAndExecute(robotomy, manager, manager);
		trySignAndExecute(pardon, president, president);
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("Unsigned execution should fail");
	try
	{
		Bureaucrat president("President", 1);
		ShrubberyCreationForm shrubbery("garden");
		std::cout << "Attempting to execute without signing" << std::endl;
		shrubbery.execute(president);
		std::cout << "Unexpected success: unsigned form executed" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	printTitle("Low grade signing failure");
	try
	{
		Bureaucrat low("Low", 150);
		ShrubberyCreationForm shrubbery("garden");
		std::cout << "Attempting to sign with a low-grade bureaucrat" << std::endl;
		shrubbery.beSigned(low);
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	return 0;
}
