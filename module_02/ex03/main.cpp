#include "Fixed.hpp"
#include "Point.hpp"

int main(void)
{
	float x, y;

	std::cout << "input a coordinates for vertice A:" << std::endl;
	std::cin >> x >> y;
	const Point	a(x, y);
	std::cout << "input a coordinates for vertice B:" << std::endl;
	std::cin >> x >> y;
	const Point	b(x, y);
	std::cout << "input a coordinates for vertice C:" << std::endl;
	std::cin >> x >> y;
	const Point	c(x, y);
	std::cout << "input a coordinates for point" << std::endl;
	std::cin >> x >> y;
	const Point	point(x, y);

	if (bsp(a, b, c, point))
		std::cout << "Point is inside the triangle" << std::endl;
	else
		std::cout << "Point is outside the triangle or on it's side/vertice" <<
		std::endl;
	return 0;
}
