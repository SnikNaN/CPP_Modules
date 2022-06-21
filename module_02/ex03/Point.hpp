#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
private:
	const Fixed	x;
	const Fixed	y;
public:
	Point();
	~Point();
	Point(const	float x, const float y);
	Point(const Point& point);
	void operator=(const Point& point);
	const Fixed& getX(void) const;
	const Fixed& getY(void) const;
};

bool	bsp(const Point a, const Point b, const Point c, const Point point);

#endif