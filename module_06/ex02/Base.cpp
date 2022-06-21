#include "Base.hpp"

Base* generate(void)
{
	std::srand(std::time(0));

	std::cout << "Generate... ";
	switch (std::rand() % 3)
	{
		case 0:
			std::cout << "A!" << std::endl;
			return (new A);
		case 1:
			std::cout << "B!" << std::endl;
			return (new B);
		default:
			std::cout << "C!" << std::endl;
			return (new C);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
	{
		std::cout << "Pointer: Object type: A" << std::endl;
	}
	else if (dynamic_cast<B*>(p) != NULL)
	{
		std::cout << "Pointer: Object type: B" << std::endl;
	}
	else if (dynamic_cast<C*>(p) != NULL)
	{
		std::cout << "Pointer: Object type: C" << std::endl;
	}
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Reference: Object type: A" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
		(void)e;
	}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Reference: Object type: B" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
		(void)e;
	}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Reference: Object type: C" << std::endl;
		return;
	}
	catch (std::exception &e)
	{
		(void)e;
	}
}