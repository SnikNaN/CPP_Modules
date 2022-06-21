#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

int main()
{
	Bureaucrat griffin("Griffin Benson", 5);
	Bureaucrat neal("Neal Barrett", 140);
	Bureaucrat sam("Sam Barrett", 150);
	Bureaucrat emil("Emil Miller", 25);
	Bureaucrat logan("Logan Lester", 70);

	/*	Shrubbery Creation Form	*/

	ShrubberyCreationForm formShrubbery("Garden");

	try
	{
		sam.executeForm(formShrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		sam.signForm(formShrubbery);
		griffin.executeForm(formShrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		neal.signForm(formShrubbery);
		neal.executeForm(formShrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		griffin.executeForm(formShrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	/*	Robotomy Request Form	*/

	RobotomyRequestForm	formRobotomy("R2D2");

	try
	{
		neal.signForm(formRobotomy);
		neal.executeForm(formRobotomy);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		emil.executeForm(formRobotomy);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		logan.signForm(formRobotomy);
		emil.executeForm(formRobotomy);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	/*	Presidential Pardon Form	*/

	PresidentialPardonForm formPardon("somebody");

	try
	{
		logan.signForm(formPardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		emil.signForm(formPardon);
		emil.executeForm(formPardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		griffin.executeForm(formPardon);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
