#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Cat: public Animal
{
private:
	Brain* _brain;
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat& cat);
	Cat& operator=(const Cat& cat);
	void makeSound() const;
};


#endif //CAT_HPP
