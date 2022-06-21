#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>

class NotFound: public std::exception
{
public:
	char const	*what() const throw()
	{
		return ("Exception: value not found");
	}
};

template <typename T>
typename T::iterator easyfind(T& container, int val)
{
	typename T::iterator it;
	it = std::find(container.begin(), container.end(), val);
	if (it == container.end())
		throw NotFound();
	return (it);
}

#endif
