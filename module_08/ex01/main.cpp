#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	Span	span1(5);
	Span	span2(5);
	Span	emptySpan(0);
	Span	oneNumberSpan(1);

	span1.addNumber(-2147483648);
	span1.addNumber(2);
	span1.addNumber(0);
	span1.addNumber(2147483647);
	span1.addNumber(2);

	std::cout << "span1: ";
	span1.printContainer();

	span2.addNumber(0);
	span2.addNumber(5);
	span2.addNumber(3553);
	span2.addNumber(214747);
	span2.addNumber(3000);

	std::cout << "span2: ";
	span2.printContainer();

	try
	{
		oneNumberSpan.addNumber(5);
//		emptySpan.addNumber(5);
//		std::cout << oneNumberSpan.shortestSpan() << std::endl;
//		std::cout << oneNumberSpan.longestSpan() << std::endl;
		std::cout << emptySpan.longestSpan() << std::endl;
		std::cout << emptySpan.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "span1 longest span: " << span1.longestSpan() << std::endl;
		std::cout << "span1 shortest span: " << span1.shortestSpan() << std::endl;
		std::cout << "span2 longest span: " << span2.longestSpan() << std::endl;
		std::cout << "span2 shortest span: " << span2.shortestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	Span	bigSpan(10000);
	std::vector<int>	bigVector;

	bigVector.reserve(10000);
	for (int i = 0; i < 10000; i++)
		bigVector.push_back(i - 5000);

	try
	{
		bigSpan.addRange(bigVector.begin(), bigVector.end());
		bigSpan.addNumber(3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::cout << "bigSpan longest span: " << bigSpan.longestSpan() << std::endl;
		std::cout << "bigSpan shortest span: " << bigSpan.shortestSpan()
			<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	//bigSpan.printContainer();

	return 0;
}
