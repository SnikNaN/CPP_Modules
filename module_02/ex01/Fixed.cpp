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
	return (value);
}

void Fixed::setRawBits(const int raw)
{
	value = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

Fixed::Fixed(const int num)
{
	value = num << fractBits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num)
{
	value = roundf(num * (1 << fractBits));
	std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const
{
	return ((float)value / (1 << fractBits));
}

int	Fixed::toInt() const
{
	return (value >> fractBits);
}

std::ostream& operator<<(std::ostream &ostream, const Fixed &num)
{
	ostream << num.toFloat();
	return (ostream);
}