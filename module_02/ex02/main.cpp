#include "Fixed.hpp"

int main( void ) 
{
	std::cout << "\nCONSTRUCTORS & CONVERSIONS\n";
	Fixed a;
	std::cout << "a (default): " << a << std::endl;
	
	Fixed b(42);
	std::cout << "b (int 42): " << b << std::endl;
	
	Fixed c(3.14f);
	std::cout << "c (float 3.14f): " << c << std::endl;
	
	Fixed d(c);
	std::cout << "d (copy of c): " << d << std::endl;
	
	std::cout << "\nCONVERSIONS\n";
	std::cout << "b.toInt(): " << b.toInt() << std::endl;
	std::cout << "c.toFloat(): " << c.toFloat() << std::endl;
	
	std::cout << "\nOMPARISON OPERATORS\n";
	Fixed x(10);
	Fixed y(20);
	Fixed z(10);
	
	std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
	std::cout << "x > y: " << (x > y) << std::endl;
	std::cout << "x >= y: " << (x >= y) << std::endl;
	std::cout << "x < y: " << (x < y) << std::endl;
	std::cout << "x <= y: " << (x <= y) << std::endl;
	std::cout << "x == z: " << (x == z) << std::endl;
	std::cout << "x != y: " << (x != y) << std::endl;
	std::cout << "0 significa false y 1 significa true\n";
	
	std::cout << "\nARITHMETIC OPERATORS\n";
	Fixed num1(5.0f);
	Fixed num2(2.5f);
	
	std::cout << "num1 = " << num1 << ", num2 = " << num2 << std::endl;
	std::cout << "num1 + num2 = " << (num1 + num2) << std::endl;
	std::cout << "num1 - num2 = " << (num1 - num2) << std::endl;
	std::cout << "num1 * num2 = " << (num1 * num2) << std::endl;
	std::cout << "num1 / num2 = " << (num1 / num2) << std::endl;
	
	std::cout << "\nINCREMENT OPERATORS\n";
	Fixed counter(5);
	std::cout << "counter = " << counter << std::endl;
	std::cout << "++counter (pre-increment): " << ++counter << std::endl;
	std::cout << "counter after: " << counter << std::endl;
	std::cout << "counter++ (post-increment): " << counter++ << std::endl;
	std::cout << "counter after: " << counter << std::endl;
	
	std::cout << "\nDECREMENT OPERATORS\n";
	Fixed countdown(5);
	std::cout << "countdown = " << countdown << std::endl;
	std::cout << "--countdown (pre-decrement): " << --countdown << std::endl;
	std::cout << "countdown after: " << countdown << std::endl;
	std::cout << "countdown-- (post-decrement): " << countdown-- << std::endl;
	std::cout << "countdown after: " << countdown << std::endl;
	
	std::cout << "\nMIN/MAX FUNCTIONS\n";
	Fixed m1(15.5f);
	Fixed m2(42.25f);
	
	std::cout << "m1 = " << m1 << ", m2 = " << m2 << std::endl;
	std::cout << "Fixed::min(m1, m2) = " << Fixed::min(m1, m2) << std::endl;
	std::cout << "Fixed::max(m1, m2) = " << Fixed::max(m1, m2) << std::endl;
	
	const Fixed cm1(10.5f);
	const Fixed cm2(30.75f);
	std::cout << "\nconst cm1 = " << cm1 << ", const cm2 = " << cm2 << std::endl;
	std::cout << "Fixed::min(cm1, cm2) = " << Fixed::min(cm1, cm2) << std::endl;
	std::cout << "Fixed::max(cm1, cm2) = " << Fixed::max(cm1, cm2) << std::endl;
	
	std::cout << "\n";
	return 0;
}