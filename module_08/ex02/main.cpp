#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::list<int> slist;
	slist.push_back(5);
	slist.push_back(17),
	slist.pop_back();
	std::cout << std::endl << slist.size() << std::endl;
	slist.push_back(3);
	slist.push_back(5);
	slist.push_back(737);
	slist.push_back(0);

	std::list<int>::iterator i1 = slist.begin();
	std::list<int>::iterator i2 = slist.end();
	++i1;
	--i1;

	std::cout << std::endl;
	while (i1 != i2)
	{
		std::cout << *i1 << std::endl;
		++i1;
	}

	std::sort(mstack.begin(), mstack.end());
	it = mstack.begin();
	ite = mstack.end();

	std::cout << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;
	std::stack<int> s(mstack);
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return (0);
}
