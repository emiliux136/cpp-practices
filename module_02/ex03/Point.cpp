#include "Point.hpp"

Point::Point()
{}

Point::~Point()
{}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
	std::cout << "Copy constructor called\n";
}

Fixed Point::getX()
{
	return (this->x);
}

Fixed Point::getY()
{
	return (this->y);
}
Point &Point::operator=(Point other)
{
	if(this==&other)
		return *this;
	(Fixed) this->y = other.getY();
	(Fixed) this->x = other.getX();
	std::cout << "Copy assigment operator called\n";
	return *this;
}