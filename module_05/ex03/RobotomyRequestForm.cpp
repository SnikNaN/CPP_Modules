#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(
		const RobotomyRequestForm &other)
{
	(void)other;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) :
	Form("robotomy request", target, 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) :
	Form(copy)
{}

void RobotomyRequestForm::executeAct() const
{
	std::srand(std::time(0));

	std::cout << "* p==>~ SOME DRILLING NOISES *" << std::endl;
	if (std::rand() % 2 == 0)
	{
		std::cout << this->getTarget() << " has been robotomized succesfully"
			<< std::endl;
	}
	else
	{
		std::cout << this->getTarget() << ": the robotomy failed " << std::endl;
	}
}