#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed(): value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

const Fixed& Fixed::operator=(const Fixed& fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(const int raw)
{
	value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}
