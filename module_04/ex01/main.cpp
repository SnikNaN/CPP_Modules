#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
	int	size = 10;
	const Animal*	array[size];

	for (int i = 0; i < size / 2; i++)
	{
		array[i] = new Dog();
	}
	for (int i = size / 2; i < size; i++)
	{
		array[i] = new Cat();
	}

	for (int i = 0; i < size; i++)
	{
		std::cout << array[i]->getType() << ":" << std::endl;
		array[i]->makeSound();
	}

	for (int i = 0; i < size; i++)
		delete array[i];

//	Dog basic;
//	Dog tmp = basic;
//	Dog tmp2(tmp);
//	basic.makeSound();
//	tmp.makeSound();
//	tmp2.makeSound();

	return 0;
}
