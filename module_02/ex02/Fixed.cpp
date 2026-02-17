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

Fixed::Fixed(const int ni) : fixedpn(ni * int(1 << fractional) + (ni >= 0 ? 0.5 : -0.5)) 
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nf) : fixedpn(nf * float(1 << fractional) + (nf >= 0 ? 0.5 : -0.5)) 
{
	std::cout << "Float constructor called\n";
}

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
  return (out);
}

//ex02
//The 6 comparison operators:

bool Fixed::operator>(const Fixed &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->toFloat() != other.toFloat());
}

//The 4 arithmetic operators:

Fixed Fixed::operator+(const Fixed &other) const
{
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
	return (this->toFloat() / other.toFloat());
}

//The 4 increment/decrement:

Fixed &Fixed::operator++()
{
	this->fixedpn++;
	return(*this);
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	operator++();
	return (copy);
}

Fixed &Fixed::operator--()
{
	this->fixedpn--;
	return(*this);
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	operator--();
	return (copy);
}

Fixed &Fixed::min(Fixed &Fixed1, Fixed &Fixed2)
{
if (Fixed1 < Fixed2)
	return Fixed1;
else
	return Fixed2;
}
const Fixed &Fixed::min(const Fixed &Fixed1, const Fixed &Fixed2)
{
if (Fixed1 < Fixed2)
	return Fixed1;
else
	return Fixed2;
}
Fixed &Fixed::max(Fixed &Fixed1, Fixed &Fixed2) 
{
	if (Fixed1 > Fixed2)
		return Fixed1;
	else
		return Fixed2;
}

// esto es lo mismo que arriba, solo que es un operador terciario, su nomenclatura es=
// si fixed 1 es mayor que fixed2 devuelve el primero, y sino el segundo...
const Fixed &Fixed::max(const Fixed &Fixed1, const Fixed &Fixed2)
{
	return Fixed1 > Fixed2 ? Fixed1 : Fixed2; 
}