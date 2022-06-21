#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
{
}

PresidentialPardonForm&
		PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	(void)other;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) :
	Form("presidential pardon", target, 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) :
	Form(copy)
{}

void PresidentialPardonForm::executeAct() const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox."
		<< std::endl;
}