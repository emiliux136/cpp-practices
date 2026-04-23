#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

static void printTitle(const std::string &title)
{
	std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main()
{
	printTitle("Default constructors + getters + operator<<");
	try
	{
		Bureaucrat defB;
		std::cout << "bureaucrat name: " << defB.getName() << ", grade: " << defB.getGrade() << std::endl;
		std::cout << defB;

		bool sign = false;
		Form defF("DefaultForm", sign, 150, 150);
		std::cout << defF << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("Form param constructor valid");
	try
	{
		bool sign = false;
		Form leaveRequest("LeaveRequest", sign, 75, 30);
		std::cout << leaveRequest << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("Form constructor invalid grades");
	try
	{
		bool sign = false;
		Form badHigh("BadHigh", sign, 0, 30);
		std::cout << badHigh << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception (sign grade too high): " << e.what() << std::endl;
	}

	try
	{
		bool sign = false;
		Form badLow("BadLow", sign, 80, 151);
		std::cout << badLow << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception (execution grade too low): " << e.what() << std::endl;
	}

	printTitle("beSigned success");
	try
	{
		Bureaucrat boss("Boss", 20);
		bool sign = false;
		Form contract("Contract", sign, 30, 10);
		std::cout << "Before sign: " << contract << std::endl;
		contract.beSigned(boss);
		std::cout << "After sign:  " << contract << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("beSigned failure (bureaucrat grade too low)");
	try
	{
		Bureaucrat intern("Intern", 140);
		bool sign = false;
		Form topSecret("TopSecret", sign, 25, 5);
		std::cout << "Before sign attempt: " << topSecret << std::endl;
		topSecret.beSigned(intern);
		std::cout << "This line should not print" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	printTitle("beSigned called twice");
	try
	{
		Bureaucrat manager("Manager", 10);
		bool sign = false;
		Form invoice("Invoice", sign, 20, 20);
		invoice.beSigned(manager);
		invoice.beSigned(manager);
		std::cout << invoice << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("Copy constructor + assignment operator");
	try
	{
		Bureaucrat sourceB("SourceB", 42);
		Bureaucrat copyB(sourceB);
		Bureaucrat assignedB("AssignedB", 120);
		assignedB = sourceB;
		std::cout << "sourceB:   " << sourceB;
		std::cout << "copyB:     " << copyB;
		std::cout << "assignedB: " << assignedB;

		bool sign = false;
		Form sourceF("SourceF", sign, 50, 25);
		Form copyF(sourceF);
		bool sign2 = false;
		Form assignedF("AssignedF", sign2, 130, 130);
		assignedF = sourceF;
		std::cout << "sourceF:   " << sourceF << std::endl;
		std::cout << "copyF:     " << copyF << std::endl;
		std::cout << "assignedF: " << assignedF << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
