#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#include <iostream>

int main()
{
	const Animal* meta = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrongCat = new WrongCat();
	WrongCat anotherWrongCat;

	std::cout << dog->getType() << ":" << std::endl;
	dog->makeSound(); //will output the dog sound!

	std::cout << cat->getType() << ":" << std::endl;
	cat->makeSound(); //will output the cat sound!

	std::cout << meta->getType() << ":" << std::endl;
	meta->makeSound();
	std::cout << std::endl;

	std::cout << wrongCat->getType() << ":" << std::endl;
	wrongCat->makeSound();

	std::cout << anotherWrongCat.getType() << ":" << std::endl;
	anotherWrongCat.makeSound();

	delete meta;
	delete dog;
	delete cat;
	delete wrongCat;

	return 0;
}
