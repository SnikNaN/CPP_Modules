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

WrongCat::WrongCat(const WrongCat &wrongCat): WrongAnimal(wrongCat)
{
	_type = wrongCat._type;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongCat)
{
	_type = wrongCat._type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "-\"Meow\"" << std::endl;
}
