#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

#include <iostream>

int main()
{
	Bureaucrat griffin("Griffin Benson", 5);
	Bureaucrat neal("Neal Barrett", 140);
	Bureaucrat sam("Sam Barrett", 150);
	Bureaucrat emil("Emil Miller", 25);
	Bureaucrat logan("Logan Lester", 70);
	Intern someRandomIntern;
	Form* someForm;

	/*	Shrubbery Creation Form	*/

	someForm = someRandomIntern.makeForm("awesome", "something");
	someForm = someRandomIntern.makeForm("shrubbery creation", "Forest");
	try
	{
		sam.executeForm(*someForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sam.signForm(*someForm);
		griffin.executeForm(*someForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		neal.signForm(*someForm);
		neal.executeForm(*someForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		griffin.executeForm(*someForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	delete someForm;
	/*	Robotomy Request Form	*/

	someForm = someRandomIntern.makeForm("robotomy request", "Bender");

	try
	{
		neal.signForm(*someForm);
		neal.executeForm(*someForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		emil.executeForm(*someForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		logan.signForm(*someForm);
		emil.executeForm(*someForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete someForm;
	/*	Presidential Pardon Form	*/

	someForm = someRandomIntern.makeForm("presidential pardon", "Morgan Holt");

	try
	{
		logan.signForm(*someForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		emil.signForm(*someForm);
		emil.executeForm(*someForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		griffin.executeForm(*someForm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	delete someForm;
	return 0;
}
