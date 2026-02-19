#include "Fixed.hpp"
#include "Point.hpp"

float tArea(Point a, Point b, Point c)
{
	float xA = a.getX().toFloat();
	float xB = b.getX().toFloat();
	float xC = c.getX().toFloat();
	float yA = a.getY().toFloat();
	float yB = b.getY().toFloat();
	float yC = c.getY().toFloat();
	float area = (xA * (yB - yC) + xB * (yC - yA) + xC * (yA - yB)) / 2;
	area = fabs(area); 
	return (area);
}

// fabs is a function used to calculate the absolute value
// of a floating-point number, so we always work with a positive value.

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float const area1 = tArea(a, b, point);
	float const area2 = tArea(b, c, point);
	float const area3 = tArea(a, c, point);
	float const areareal = tArea(a, b, c);

	if(!area1 || !area2 || !area3)
		return false;
	else if (area1 + area2 + area3 == areareal)
		return true;
	else
		return false;
}