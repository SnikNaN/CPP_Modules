#ifndef ITER_HPP
#define ITER_HPP

#include <cstdlib>

template <class T>
void	iter(T* array, size_t size, void (*f)(T& elem))
{
	if (array != NULL && f != NULL)
		for (size_t i = 0; i < size; i++)
			f(array[i]);
}

template <class T>
void	iter(const T* array, size_t size, void (*f)(const T& elem))
{
	if (array != NULL && f != NULL)
		for (size_t i = 0; i < size; i++)
			f(array[i]);
}

#endif
