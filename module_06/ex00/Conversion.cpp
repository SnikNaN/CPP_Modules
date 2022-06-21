#include "Conversion.hpp"

Conversion::Conversion()
{}

Conversion::~Conversion()
{
}

Conversion::Conversion(const Conversion &copy)
{
	*this = copy;
}

Conversion &Conversion::operator=(const Conversion &other)
{
	(void)other;
	return (*this);
}

void Conversion::convert(const std::string &literal)
{
	std::string	valChar;
	long int	valInt;
	double		valDouble;
	char*		end;
	double		whole;
	unsigned char	c;

	if (literal.length() == 1 && std::isprint(literal[0])
			&& !std::isdigit(literal[0])) //input is the single char literal
	{
		valChar = literal[0];
		std::cout << "char: '" << valChar << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(valChar[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(valChar[0]) << ".0f"
			<< std::endl;
		std::cout << "double: " << static_cast<double>(valChar[0]) << ".0"
			<< std::endl;
		return;
	}
	else
	{
		valDouble = std::strtod(literal.c_str(), &end);
		std::string temp(end);
		if (!(temp == "f"  || temp.empty()) || errno == ERANGE) //bad input or double out of range
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}
		else
		{
			if (valDouble >= 0 && valDouble < UCHAR_MAX + 1)
			{
				c = static_cast<unsigned char>(valDouble);
				if (!std::isprint(c))
					std::cout << "char: Non displayable" << std::endl;
				else
					std::cout << "char: '" << c << "'" << std::endl;
			}
			else
				std::cout << "char: impossible" << std::endl;
			valInt = static_cast<long int>(valDouble);
			if (valInt > INT_MAX || valInt < INT_MIN)
				std::cout << "int: impossible" << std::endl;
			else
				std::cout << "int: " << static_cast<int>(valInt) << std::endl;
			if (modf(valDouble, &whole) == 0)
				std::cout << std::fixed << std::setprecision(1);
			if (valDouble > std::numeric_limits<float>::max())
				std::cout << "float: impossible" << std::endl;
			else
			{
				std::cout << "float: " << (valDouble == INFINITY ? "+" : "")
					<< static_cast<float>(valDouble) << "f" << std::endl;
			}
			std::cout << "double: " << (valDouble == INFINITY ? "+" : "")
				<< valDouble << std::endl;
		}
	}
}
