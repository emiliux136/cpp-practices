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

/* Este constructor toma un entero y lo convierte a formato de punto fijo 
multiplicándolo por 2^fractional y ajustando ligeramente para redondeo. 
Así, la variable interna fixedpn ya está lista para representar el número como 
punto fijo y poder usarla en operaciones o convertirla de vuelta a float/int. */

Fixed::Fixed(const int ni) : fixedpn(ni * int(1 << fractional) + (ni >= 0 ? 0.5 : -0.5)) 
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float nf) : fixedpn(nf * float(1 << fractional) + (nf >= 0 ? 0.5 : -0.5)) 
{
	std::cout << "Float constructor called\n";
}

/*Esa línea toma el número almacenado en formato de punto fijo (fixedpn),
que en realidad es un entero que ya incluye la parte decimal multiplicada 
por 2^fractional, y lo convierte a un float real dividiéndolo entre 2^fractional 
(1 << fractional). Esto “mueve la coma” a su posición correcta y devuelve el valor 
decimal exacto, incluyendo los decimales, en lugar de solo la parte entera. 
Básicamente, reconstruye el número original que querías representar con punto fijo.*/

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