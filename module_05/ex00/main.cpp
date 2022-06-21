#include "Bureaucrat.hpp"

#include <iostream>

int main()
{
	Bureaucrat bureaucrat_1("Griffin Benson", 1);
	Bureaucrat bureaucrat_2("Neal Barrett", 150);
	try
	{
		bureaucrat_2.upGrade();
		bureaucrat_1.upGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat2("Willis Stevenson", 500);
	}
	catch (std::exception &e)
	{
		std::cout << "Failed to create: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bureaucrat2("Willis Stevenson", -45);
	}
	catch (std::exception &e)
	{
		std::cout << "Failed to create: " << e.what() << std::endl;
	}
	try
	{
		bureaucrat_1.downGrade();
		bureaucrat_2.downGrade();
		bureaucrat_2.downGrade();
		bureaucrat_1.upGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
