#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec;

	vec.reserve(20);
	for (int i = 0; i < 20; i++)
		vec.push_back(i + 5);

	for (std::vector<int>::iterator it = vec.begin(); it < vec.end(); it++)
		std::cout << "[" << *it << "]";
	std::cout << std::endl;
	try
	{
		std::cout << *easyfind(vec, 6) << " : success" << std::endl;
		std::cout << *easyfind(vec, 22) << " : success" << std::endl;
		std::cout << *easyfind(vec, 20) << " : success" << std::endl;
		std::cout << *easyfind(vec, 8) << " : success" << std::endl;
		std::cout << *easyfind(vec, 24) << " : success" << std::endl;
		std::cout << *easyfind(vec, 2) << " : success" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
