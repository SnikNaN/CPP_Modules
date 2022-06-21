#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog: public Animal
{
private:
	Brain* _brain;
public:
	Dog();
	virtual ~Dog();
	Dog(const Dog& dog);
	Dog& operator=(const Dog& dog);
	void makeSound() const;
};


#endif //DOG_HPP
