#ifndef CONVERSION_HPP
#define CONVERSION_HPP

#include <iostream>
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <iomanip>
#include <cmath>

class Conversion
{
private:
	Conversion(const Conversion& copy);
	Conversion& operator=(const Conversion& other);
	Conversion();
public:
	~Conversion();

	static void convert(const std::string& literal);
};

#endif //CONVERSION_HPP
