#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "*Dog* constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();

}

Dog::~Dog()
{
	std::cout << "*Dog* destructor called" << std::endl;
	delete _brain;
}

Dog::Dog(const Dog &dog): Animal(dog)
{
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog)
{
	_type = dog._type;
	_brain = new Brain();
	*_brain = *dog._brain;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "-\"Woof\"" << std::endl;
}
