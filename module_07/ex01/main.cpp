#include <iostream>
#include "iter.hpp"

template <typename T>
void addFive(T& num)
{
	num += 5;
}

template <typename T>
void print(T& some)
{
	std::cout << "[" << some << "]";
}

void printUpper(std::string& str)
{
	std::cout << "[";
	for (size_t j = 0; j < str.length(); j++)
		std::cout << (char)std::toupper(str[j]);
	std::cout << "]";
}

int main( void )
{
	int	arrayInt[] = {1, 2, 3, 4, 5};
	float arrayFloat[] = {1.5f, 2.5f, 3.5f};
	std::string text[] = {"one", "two", "three"};

	iter(arrayInt, 5, print);
	std::cout << std::endl;
	iter(arrayInt, 5, addFive);
	iter(arrayInt, 5, print);
	std::cout << std::endl << std::endl;

	iter(text, 3, print);
	std::cout << std::endl;
	iter(text, 3, printUpper);
	std::cout << std::endl << std::endl;

	iter(arrayFloat, 3, print);
	std::cout << std::endl;
	iter(arrayFloat, 3, addFive);
	iter(arrayFloat, 3, print);
	std::cout << std::endl << std::endl;

	return 0;
}