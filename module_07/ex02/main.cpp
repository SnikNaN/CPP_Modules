#include <iostream>
#include "Array.hpp"

class Awesome
{
public:
	Awesome(void) : _n(0) {}
	Awesome( int n ) : _n( n ) {}
	Awesome& operator=(const Awesome & a) { _n = a._n; return *this; }
	bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
	bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
	bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
	bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
	bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
	bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
	int get_n() const { return _n; }
	void set_n(int n) { _n = n; }
private:
	int _n;
};
std::ostream & operator<<(std::ostream & o, const Awesome &a)
{
	o << a.get_n(); return o;
}

#define MAX_VAL 15
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);

	Array<int> *a = new Array<int>();
	std::cout << *a << std::endl;
	delete a;

	std::cout << numbers;

	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand() % 100;
		numbers[i] = value;
		mirror[i] = value;
	}

	std::cout << numbers;

	Array<int> tmp = numbers;
	std::cout << "tmp: " << tmp;
	Array<int> test(tmp);
	std::cout << "test: " << test;

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	std::cout << "numbers: size = " << numbers.size() << " " << numbers;
	std::cout << "tmp: size = " << tmp.size() << " " << tmp;
	Array<int> *empty = new Array<int>(5);
	test = *empty;
	for (size_t i = 0; i < empty->size(); i++)
		(*empty)[i] = empty->size() - i;
	std::cout << "test: size = " << test.size() << " " << test;
	std::cout << "empty: size = " << empty->size() << " " << *empty;
	delete [] mirror;
	delete empty;

	Array<Awesome> arr(3);
	for (int i = 0; i < 3; i++)
		arr[i].set_n(i);
	std::cout << "arr: size = " << arr.size() << " " << arr;

	return 0;
}