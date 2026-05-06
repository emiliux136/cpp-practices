#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>  // rand, srand
#include <ctime>    // time

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

Base * generate(void)
{
	int r = std::rand() % (3);
	switch (r)
	{
	case 0:
		return new A;
		break;
	case 1:
		return new B;
		break;
	case 2:
		return new C;
		break;
	default:
		break;
	}
	return new Base;
}

void identify(Base* p)
{
	if(dynamic_cast<A*>(p))  // if the casting of a pointer fails it returns nullptr, if not is a valid pointer.
		std::cout << "A";
	else if(dynamic_cast<B*>(p))
		std::cout << "B";
	else if(dynamic_cast<C*>(p))
		std::cout << "C";
}

void identify(Base& p)
{
	try //if it fails throws an exception std::bad_cast. No nullptr option.
	{
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e){}
	try
	{
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e){}
	
}

int main() 
{
	std::srand(std::time(0)); //starts the seed for the randomized decisions.
	Base *prueba = generate();
	Base &ref = *prueba;
	identify(prueba);
	identify(ref);
	delete prueba;
	return (0);
}