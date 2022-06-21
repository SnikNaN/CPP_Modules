#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

class Span
{
private:
	std::vector<int> _container;
	size_t	_n;
public:
	Span();
	virtual ~Span();
	Span(const Span& copy);
	Span& operator=(const Span& other);
	Span(size_t n);

	class Full: public std::exception
	{
		const char* what() const throw();
	};

	class NoSpan: public std::exception
	{
		const char* what() const throw();
	};

	void	addNumber(int n);
	long	shortestSpan();
	long	longestSpan();
	void	addRange(const std::vector<int>::iterator &begin,
							const std::vector<int>::iterator &end);

	void	printContainer() const;
};




#endif //SPAN_HPP
