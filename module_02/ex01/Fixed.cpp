#include "Fixed.hpp"

Fixed::Fixed() : fixedpn(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &other) : fixedpn(other.fixedpn)
{
	std::cout << "Copy constructor called\n";
}
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
		return *this;
	this->setRawBits(other.getRawBits());
	return *this;
}

int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called\n";
	return (fixedpn);
}

void Fixed::setRawBits( int const raw )
{
	fixedpn = raw;
}

//ex01

/* This constructor takes an integer and converts it to fixed-point format
by multiplying it by 2^fractional and slightly adjusting it for rounding.
This way, the internal variable fixedpn is ready to represent the number in
fixed-point form and can be used in operations or converted back to float/int. */

Fixed::Fixed(const int ni) : fixedpn(ni * int(1 << fractional) + (ni >= 0 ? 0.5 : -0.5)) 
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nf) : fixedpn(nf * float(1 << fractional) + (nf >= 0 ? 0.5 : -0.5)) 
{
	std::cout << "Float constructor called\n";
}

/*That line takes the number stored in fixed-point format (fixedpn),
which is actually an integer that already includes the fractional part multiplied
by 2^fractional, and converts it into a real float by dividing it by 2^fractional
(1 << fractional).
This “moves the decimal point” back to its correct position and returns the exact
decimal value, including the fractional part, instead of just the integer portion.
Basically, it reconstructs the original number you wanted to represent using fixed-point format.*/

float Fixed::toFloat( void ) const
{
	float ret;
	ret = float(fixedpn) / float(1 << fractional);
	return ret;
}

int Fixed::toInt( void ) const
{	
	int ret;
	ret = int(fixedpn) / int(1 << fractional);
	return ret;
}

std::ostream &operator<<(std::ostream &out, const Fixed &right) 
{
	out << right.toFloat();
	//std::cout << "\n<< operator called\n";
	return (out);
}