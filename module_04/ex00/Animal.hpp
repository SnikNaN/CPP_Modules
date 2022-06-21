#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>

class Animal
{
protected:
	std::string	_type;

public:
	Animal();
	virtual ~Animal();
	Animal(const Animal& animal);
	Animal& operator=(const Animal& animal);

	virtual void makeSound() const;
	std::string getType() const;
};


#endif //ANIMAL_HPP
