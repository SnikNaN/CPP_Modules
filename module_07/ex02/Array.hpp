#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <iostream>

template <class T>
class Array
{
private:
	T *_arr;
	size_t _size;

public:
	Array();
	Array(size_t n);
	~Array();
	Array(const Array &copy);

	Array &operator=(const Array &other);
	T &operator[](size_t index);
	const T &operator[](size_t index) const;

	size_t size() const;

	class OutOfIndexException : public std::exception
	{
		const char* what() const throw();
	};
};

#include "Array.tpp"

#endif
