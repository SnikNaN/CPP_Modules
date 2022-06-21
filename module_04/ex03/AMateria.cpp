#include "AMateria.hpp"

AMateria::~AMateria()
{
	std::cout << "*AMateria* destructor called" << std::endl;
}

AMateria::AMateria(const std::string &type):
	_type(type)
{
	std::cout << "*AMateria* constructor \"" << type << "\" called" << std::endl;
}

const std::string &AMateria::getType() const
{
	return (_type);
}
