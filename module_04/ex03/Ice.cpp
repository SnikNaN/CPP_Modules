#include "Ice.hpp"

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::Ice():
	AMateria("ice")
{
	std::cout << "*Ice* default constructor called" << std::endl;
}

Ice::~Ice()
{
	std::cout << "*Ice* destructor called" << std::endl;
}

AMateria *Ice::clone() const
{
	AMateria* cloned = new Ice();
	return (cloned);
}

Ice::Ice(const Ice &copy) : AMateria(copy.getType())
{
	std::cout << "*Ice* copy constructor called" << std::endl;
	*this = copy;
}

Ice &Ice::operator=(const Ice &copy)
{
	_type = copy._type;
	return (*this);
}
