#ifndef POINT_CPP
# define POINT_CPP

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Fixed.hpp"

class Point
{
private:
	Fixed const x;
	Fixed const y;
public:
	Point();
	Point(const Point &other);
	Point &operator=(Point other);
	Fixed getX();
	Fixed getY();
	~Point();
};

#endif