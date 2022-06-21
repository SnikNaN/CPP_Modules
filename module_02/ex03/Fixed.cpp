#include "Fixed.hpp"

const int Fixed::fractBits = 8;

Fixed::Fixed(): value(0)
{
}

Fixed::Fixed(const Fixed& fixed)
{
	*this = fixed;
}

const Fixed& Fixed::operator=(const Fixed& fixed)
{
	value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits(void) const
{
	return (value);
}

void Fixed::setRawBits(const int raw)
{
	value = raw;
}

Fixed::Fixed(const int num)
{
	value = num << fractBits;
}

Fixed::Fixed(const float num)
{
	value = roundf(num * (1 << fractBits));
}

float Fixed::toFloat() const
{
	return ((float)value / (1 << fractBits));
}

int	Fixed::toInt() const
{
	return (value >> fractBits);
}

bool Fixed::operator>(const Fixed& other) const
{
	return (this->getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->getRawBits() != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed	add;

	add.setRawBits(this->getRawBits() + other.getRawBits());
	return (add);
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed	sub;

	sub.setRawBits(this->getRawBits() - other.getRawBits());
	return (sub);
}

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed	mul;

	mul.setRawBits(((long)this->getRawBits() * other.getRawBits()) >> fractBits);
	return (mul);
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed	div;

	div.setRawBits(((long)this->getRawBits() << fractBits) / other.getRawBits());
	return (div);
}

Fixed& Fixed::operator++(void)
{
	this->value++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed	tmp(*this);
	this->value++;
	return (tmp);
}

Fixed& Fixed::operator--(void)
{
	this->value--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed	tmp(*this);
	this->value--;
	return (tmp);
}

Fixed& Fixed::min(Fixed &num1, Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

const Fixed& Fixed::min(const Fixed &num1, const Fixed &num2)
{
	if (num1 < num2)
		return (num1);
	else
		return (num2);
}

Fixed& Fixed::max(Fixed &num1, Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

const Fixed& Fixed::max(const Fixed &num1, const Fixed &num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}

std::ostream& operator<<(std::ostream &ostream, const Fixed &num)
{
	if (num.toInt() > 9)
		ostream << (num.toInt() / 10);
	if ((num.getRawBits() << 24) != 0)
		ostream << (num - Fixed(num.toInt() / 10 * 10)).toFloat();
	else
		ostream << num.toInt() % 10;
	return (ostream);
}