#include "Span.hpp"

Span::Span():
	_n(0)
{}

Span::Span(size_t n):
	_n(n)
{
	_container.reserve(n);
}

Span::~Span()
{}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_container = other._container;
		_n = other._n;
	}
	return (*this);
}

void Span::addNumber(int n)
{
	if (_container.size() == _n)
		throw Full();
	_container.push_back(n);
}

long Span::longestSpan()
{
	if (_container.size() <= 1)
		throw NoSpan();
	std::vector<int> sorted = _container;

	std::sort(sorted.begin(), sorted.end());
	return (static_cast<long>(*sorted.rbegin())
				- static_cast<long>(*sorted.begin()));
}

long Span::shortestSpan()
{
	if (_container.size() <= 1)
		throw NoSpan();
	std::vector<int> sorted = _container;
	long min = LONG_MAX;
	std::sort(sorted.begin(), sorted.end());
	for (std::vector<int>::iterator i = sorted.begin() + 1; i != sorted.end(); i++)
	{
		if (static_cast<long>(*i) - static_cast<long>(*(i - 1)) < min)
			min = static_cast<long>(*i) - static_cast<long>(*(i - 1));
		if (min == 0)
			return (0);
	}
	return (min);
}

void Span::printContainer() const
{
	std::vector<int>::const_iterator it;

	for (it = _container.begin(); it != _container.end(); it++)
	{
		std::cout << "[" << *it << "]";
	}
	std::cout << std::endl;
}

void
Span::addRange(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end)
{
	if ( (_n - _container.size()) < static_cast<unsigned long>(end - begin))
		throw Full();
	_container.insert(_container.end(), begin, end);
}

const char *Span::Full::what() const throw()
{
	return ("Exception: container doesn't have enough memory");
}

const char *Span::NoSpan::what() const throw()
{
	return ("Exception: no span can be found");
}