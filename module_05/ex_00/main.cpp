#include "Bureaucrat.hpp"

#include <iostream>

static void printTitle(const std::string &title)
{
	std::cout << "\n========== " << title << " ==========" << std::endl;
}

int main()
{
	printTitle("Default constructor + getters + operator<<");
	try
	{
		Bureaucrat def;
		std::cout << "name: " << def.getName() << ", grade: " << def.getGrade() << std::endl;
		std::cout << def;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("Param constructor valid");
	try
	{
		Bureaucrat alice("Alice", 42);
		std::cout << alice;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("Param constructor invalid (too high)");
	try
	{
		Bureaucrat badHigh("BadHigh", 0);
		std::cout << badHigh;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	printTitle("Param constructor invalid (too low)");
	try
	{
		Bureaucrat badLow("BadLow", 151);
		std::cout << badLow;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	printTitle("incrementGrade normal + limit exception");
	try
	{
		Bureaucrat up("Up", 2);
		std::cout << "Before increment: " << up;
		up.incrementGrade();
		std::cout << "After increment:  " << up;
		up.incrementGrade();
		std::cout << "This line should not print" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	printTitle("decrementGrade normal + limit exception");
	try
	{
		Bureaucrat down("Down", 149);
		std::cout << "Before decrement: " << down;
		down.decrementGrade();
		std::cout << "After decrement:  " << down;
		down.decrementGrade();
		std::cout << "This line should not print" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	printTitle("Copy constructor");
	try
	{
		Bureaucrat original("Original", 20);
		Bureaucrat copy(original);
		std::cout << "original: " << original;
		std::cout << "copy:     " << copy;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	printTitle("Assignment operator");
	try
	{
		Bureaucrat a("A", 10);
		Bureaucrat b("B", 130);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "a: " << a;
		std::cout << "b: " << b;
		b = a;
		std::cout << "After b = a:" << std::endl;
		std::cout << "a: " << a;
		std::cout << "b: " << b;
		std::cout << "(If assignment is correctly implemented, b grade should match a grade.)" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}

	return 0;
}
