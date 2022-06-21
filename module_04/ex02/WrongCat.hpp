#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"
#include <iostream>

class WrongCat: public WrongAnimal
{
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat& cat);
	WrongCat& operator=(const WrongCat& cat);
	void makeSound() const;
};


#endif //WRONGCAT_HPP
