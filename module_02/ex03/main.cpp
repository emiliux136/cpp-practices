#include "Fixed.hpp"
#include "Point.hpp"

void validation(Point const a, Point const b, Point const c, Point const check)
{
	if(bsp(a, b, c, check))
		std::cout << "Point checked is inside the triangle\n";
	else
		 std::cout << "Point checked is NOT inside the triangle\n";
}

int main(void)
{
Point vertex1(-4, -3);
Point vertex2(4, -1);
Point vertex3(-4, 4);

Point p1(float(-3.99), -1);
Point p2(2, 2);

validation(vertex1, vertex2, vertex3, p1);
//validation(vertex1, vertex2, vertex3, p2);
return 0;
}