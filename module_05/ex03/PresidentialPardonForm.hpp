#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

#include <iostream>

class PresidentialPardonForm: public Form
{
private:
	PresidentialPardonForm();
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& copy);
	~PresidentialPardonForm();

	void executeAct() const;
};



#endif //PRESIDENTIALPARDONFORM_HPP
