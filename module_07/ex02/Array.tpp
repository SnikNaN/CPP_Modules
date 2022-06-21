#include "Array.hpp"

template <class T>
Array<T>::Array():
	_arr(NULL),
	_size(0)
{
	std::cout << "Default constructor called" << std::endl;
}

template <class T>
Array<T>::~Array()
{
	if (_size > 0)
		delete[] _arr;
}

template <class T>
Array<T>::Array(size_t n)
{
	_arr = new T[n];
	_size = n;
	for (size_t i = 0; i < _size; i++)
		_arr[i] = 0;
}

template <class T>
Array<T>::Array(const Array &copy):
	_arr(NULL),
	_size(0)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

template <class T>
Array<T>& Array<T>::operator=(const Array &other)
{
	if (_size > 0)
		delete[] _arr;
	_arr = NULL;
	_size = other._size;

	if (_size != 0)
	{
		_arr = new T[_size];
		for (size_t i = 0; i < _size; i++)
			_arr[i] = other._arr[i];
	}
	return (*this);
}

template <class T>
T& Array<T>::operator[](size_t index)
{
	if (index >= _size)
		throw OutOfIndexException();
	return (_arr[index]);
}

template <class T>
const T& Array<T>::operator[](size_t index) const
{
	return (operator=(index));
}

template <class T>
size_t Array<T>::size() const
{
	return (_size);
}

template<class T>
const char* Array<T>::OutOfIndexException::what() const throw()
{
	return "OutOfIndexException: Index is out of range";
}

template <class T>
std::ostream &operator<<(std::ostream &stream, Array<T>& print)
{
	stream << "[ ";
	if (print.size() == 0)
		stream << "NULL";
	else
	{
		for (size_t i = 0; i < print.size() - 1; i++)
			stream << print[i] << ", ";
		stream << print[print.size() - 1];
	}
	stream << " ]" << std::endl;
	return stream;
}