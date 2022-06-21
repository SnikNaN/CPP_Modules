#include "Cure.hpp"

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}

Cure::Cure():
	AMateria("cure")
{
	std::cout << "*Cure* default constructor called" << std::endl;
}

Cure::~Cure()
{
	std::cout << "*Cure* destructor called" << std::endl;
}

AMateria *Cure::clone() const
{
	AMateria* cloned = new Cure();
	return (cloned);
}

Cure::Cure(const Cure &copy) : AMateria(copy.getType())
{
	std::cout << "*Cure* copy constructor called" << std::endl;
	*this = copy;
}

Cure &Cure::operator=(const Cure &copy)
{
	_type = copy._type;
	return (*this);
}
