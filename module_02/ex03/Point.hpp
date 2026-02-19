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
	Point(Fixed x, Fixed y);
	Point(const Point &other);
	Point &operator=(Point other);
	Fixed getX();
	Fixed getY();
	~Point();
};

bool bsp(Point const a, Point const b, Point const c, Point const check);
float tArea(Point a, Point b, Point c);
void validation(Point const a, Point const b, Point const c, Point const check);

#endif