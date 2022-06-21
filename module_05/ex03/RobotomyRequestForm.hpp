#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public Form
{
private:
	RobotomyRequestForm();
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
public:
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& copy);
	~RobotomyRequestForm();

	void executeAct() const;
};



#endif //ROBOTOMYREQUESTFORM_HPP
