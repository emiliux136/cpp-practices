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

//fabs es una función que se utiliza para calcular el valor absoluto
//de un número de punto flotante, as'i siempre trabajaremos en + (positivo).