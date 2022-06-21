#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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

	int getRawBits(void) const;
	void setRawBits(const int raw);
};

#endif
