#ifndef FIXED_CPP
# define FIXED_CPP

#include <iostream>

class Fixed
{
private:
	int fixedpn;
	static const int fractional = 8;
public:
	Fixed(); 								//Constructor
	Fixed(const Fixed &other); 				//Constructor copia.
	Fixed &operator=(const Fixed &other); 	//Asignacion de operador de copia
	~Fixed();								//Destructor
	int getRawBits( void ) const;
	void setRawBits( int const raw );

	Fixed(const int ni); //Constructor que pasa un int a fixed-point.
	Fixed(const float nf); //Constructor que pasa un float a fixed-point.
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &out, const Fixed &right);

#endif