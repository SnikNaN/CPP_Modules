#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern created" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destroyed" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	*this = copy;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}

template <typename T>
Form *Intern::newForm(const std::string &target) const
{
	return (new T(target));
}

Form *Intern::makeForm(const std::string &name, const std::string &target) const
{
	Form *createdForm;

	t_forms	forms[] =
		{
		{ "shrubbery creation", &Intern::newForm<ShrubberyCreationForm> },
		{ "robotomy request", &Intern::newForm<RobotomyRequestForm> },
		{ "presidential pardon", &Intern::newForm<PresidentialPardonForm> }
		};
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i].formName)
		{
			createdForm = (this->*forms[i].form)(target);
			std::cout << "Intern creates " << *createdForm << std::endl;
			return (createdForm);
		}
	}
	std::cout << "Intern couldn't find the " << name << " form" << std::endl;
	return (NULL);
}
