#include "Point.hpp"

Point::Point(): x(0), y(0)
{}

Point::~Point()
{}

Point::Point(const	float x, const float y): x(x), y(y)
{}

Point::Point(const Point& point): x(point.x), y(point.y)
{}

void Point::operator=(const Point& point)
{
	(void)point;
}

const Fixed& Point::getX() const
{
	return (this->x);
}

const Fixed& Point::getY() const
{
	return (this->y);
}