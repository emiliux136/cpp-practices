#include "Fixed.hpp"

//ex00

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
