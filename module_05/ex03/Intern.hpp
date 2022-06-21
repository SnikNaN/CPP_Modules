#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

class Intern
{
private:
	template<typename T>
	Form* newForm(const std::string &target) const;
	typedef struct	s_forms
	{
		std::string	formName;
		Form*(Intern::*form)(const std::string&) const;
	}				t_forms;
public:
	Intern();
	~Intern();
	Intern(const Intern& copy);
	Intern& operator=(const Intern& other);

	Form* makeForm(const std::string& name, const std::string& target) const;
};

#endif //INTERN_HPP
