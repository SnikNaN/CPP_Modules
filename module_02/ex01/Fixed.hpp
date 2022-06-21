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

	int getRawBits(void) const;
	void setRawBits(const int raw);
};

std::ostream& operator<<(std::ostream& ostream, const Fixed& num);

#endif
