#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#include <cstdlib>
#include <ctime>

int main() {
	std::srand(std::time(NULL));
	try {
		Intern someRandomIntern;
		Form* rrf;
		Form* xd;
		Form* lol;
		rrf = someRandomIntern.makeForm("PresidentialPardonForm", "Bender");
		std::cout << rrf->getName() << std::endl;
		rrf->executer();
		xd = someRandomIntern.makeForm("RobotomyRequestForm","HaveFun");
		xd->executer();
		lol = someRandomIntern.makeForm("ShrubberyCreationForm","LostYourLife");
		lol->executer();
		delete rrf;

	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}