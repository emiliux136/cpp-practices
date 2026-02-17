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

	Fixed(const int ni); 					//Constructor que pasa un int a fixed-point.
	Fixed(const float nf); 					//Constructor que pasa un float a fixed-point.
	float toFloat( void ) const;
	int toInt( void ) const;

	bool operator>(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed &operator++();
	Fixed operator++(int);					//los int no se usan para nada en la funcion, sirven para diferenciar el ++x del x++.
	Fixed &operator--();
	Fixed operator--(int);
	static Fixed &min(Fixed &Fixed1, Fixed &Fixed2);
	static const Fixed &min(const Fixed &Fixed1, const Fixed &Fixed2);
	static Fixed &max(Fixed &Fixed1, Fixed &Fixed2);
	static const Fixed &max(const Fixed &Fixed1, const Fixed &Fixed2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &right);

#endif