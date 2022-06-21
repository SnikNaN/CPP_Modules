#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
private:
	int					value;
	const static int	fractBits;
public:
	Fixed();
	Fixed(const Fixed& fixed);
	const Fixed& operator=(const Fixed& fixed);
	~Fixed();

	Fixed(const int num);
	Fixed(const float num);
	float	toFloat(void) const;
	int		toInt(void) const;

	bool	operator>(const Fixed& other) const;
	bool	operator<(const Fixed& other) const;
	bool	operator>=(const Fixed& other) const;
	bool	operator<=(const Fixed& other) const;
	bool	operator==(const Fixed& other) const;
	bool	operator!=(const Fixed& other) const;

	Fixed	operator+(const Fixed& other) const;
	Fixed	operator-(const Fixed& other) const;
	Fixed	operator*(const Fixed& other) const;
	Fixed	operator/(const Fixed& other) const;

	Fixed&	operator++(void);
	Fixed	operator++(int);
	Fixed&	operator--(void);
	Fixed	operator--(int);

	static Fixed&		min(Fixed& num1, Fixed& num2);
	const static Fixed&	min(const Fixed& num1, const Fixed& num2);
	static Fixed&		max(Fixed& num1, Fixed& num2);
	const static Fixed&	max(const Fixed& num1, const Fixed& num2);

	int getRawBits(void) const;
	void setRawBits(const int raw);
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& num);

#endif
