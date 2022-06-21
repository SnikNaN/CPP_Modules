#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "*Brain* constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = std::to_string(i);
	}
}

Brain::~Brain()
{
	std::cout << "*Brain* destructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain)
{
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		_ideas[i] = brain._ideas[i];
	}
	return (*this);
}