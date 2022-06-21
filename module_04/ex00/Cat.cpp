#include "Cat.hpp"

Cat::Cat()
{
	_type = "Cat";
	std::cout << "*Cat* constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << "*Cat* destructor called" << std::endl;
}

Cat::Cat(const Cat &cat): Animal(cat)
{
	_type = cat._type;
}

Cat &Cat::operator=(const Cat &cat)
{
	_type = cat._type;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "-\"Meow\"" << std::endl;
}
