#include "Point.hpp"
#include "Fixed.hpp"

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	Fixed	m1;
	Fixed	m2;
	Fixed	m3;

	m1 = (a.getX() - point.getX()) * (b.getY() - a.getY())
			- (b.getX() - a.getX()) * (a.getY() - point.getY());
	m2 = (b.getX() - point.getX()) * (c.getY() - b.getY())
			- (c.getX() - b.getX()) * (b.getY() - point.getY());
	m3 = (c.getX() - point.getX()) * (a.getY() - c.getY())
			- (a.getX() - c.getX()) * (c.getY() - point.getY());
	if ((m1 > 0 && m2 > 0 && m3 > 0) || (m1 < 0 && m2 < 0 && m3 < 0))
		return (true);
	return (false);
}