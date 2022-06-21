#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	_type = "WrongCat";
	std::cout << "*WrongCat* constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "*WrongCat* destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &WrongCat)
{
	_type = WrongCat._type;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat)
{
	_type = WrongCat._type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "-\"Meow\"" << std::endl;
}
