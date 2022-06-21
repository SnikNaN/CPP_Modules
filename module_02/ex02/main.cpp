#include "Fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "a = " << a << std::endl;
	std::cout << "return value of ++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "return value of a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << std::endl;

	std::cout << "b = " << b << std::endl;
	std::cout << "return value of --b = " << --b << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "return value of b-- = " << b-- << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << std::endl;

	if (a != b)
		std::cout << "a != b";
	std::cout << std::endl;
	if (a == a)
		std::cout << "a == a";
	std::cout << std::endl;

	std::cout << (Fixed(2000) * Fixed(4000) + Fixed(0.421875f))<< std::endl;
	std::cout << Fixed(10000) / Fixed(4000) << std::endl;
	std::cout << Fixed(2) / Fixed(8) << std::endl;
	std::cout << Fixed(8388607) - Fixed(0.42188f) << std::endl;
	std::cout << (Fixed(8388607) + Fixed(0.99609f)) << std::endl;

	std::cout << "max(a,b): " << Fixed::max(a, b) << std::endl;
	std::cout << "min(a,b): " << Fixed::min(a, b) << std::endl;

	return 0;
}
