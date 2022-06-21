#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "*Cat* constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::~Cat()
{
	std::cout << "*Cat* destructor called" << std::endl;
	delete _brain;
}

Cat::Cat(const Cat &cat): Animal(cat)
{
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat)
{
	std::cout << "*Cat* copy assignment operator called" << std::endl;
	_type = cat._type;
	_brain = new Brain();
	*_brain = *cat._brain;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "-\"Meow\"" << std::endl;
}
