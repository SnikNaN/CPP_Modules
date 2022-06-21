#include "Animal.hpp"

Animal::Animal():
	_type("Unknown Animal")
{
	std::cout << "*Animal* constructor called" << std::endl;
}

Animal::~Animal()
{
	std::cout << "*Animal* destructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	std::cout << "*Animal* copy constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "*Animal* assigment operator called" << std::endl;
	_type = animal._type;
	return (*this);
}

std::string Animal::getType() const
{
	return (_type);
}
