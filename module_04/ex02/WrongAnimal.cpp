#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():
	_type("Unknown WrongAnimal")
{
	std::cout << "*WrongAnimal* constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "*WrongAnimal* destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &animal):
	_type(animal._type)
{}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &animal)
{
	_type = animal._type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Unknown animal doesn't know how to make sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (_type);
}
