#include "Dog.hpp"

Dog::Dog()
{
	_type = "Dog";
	std::cout << "*Dog* constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << "*Dog* destructor called" << std::endl;
}

Dog::Dog(const Dog &dog): Animal(dog)
{
	_type = dog._type;
}

Dog &Dog::operator=(const Dog &dog)
{
	_type = dog._type;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "-\"Woof\"" << std::endl;
}
