#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <iostream>

class Bureaucrat;

class Form
{
private:
	Form& operator=(const Form& other);

	const static int	_minGrade = 150;
	const static int 	_maxGrade = 1;

	const std::string	_name;
	const std::string	_target;
	const int			_gradeToSign;
	const int			_gradeToExec;
	bool 				_signed;
public:
	Form();
	Form(const std::string &name, const std::string &target, int gradeToSign, int gradeToExec);
	virtual ~Form();
	Form(const Form& copy);

	class GradeTooHighException: public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		const char* what() const throw();
	};

	const std::string &getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExec() const;
	void beSigned(const Bureaucrat& bureaucrat);
	void execute(const Bureaucrat& executor) const;
	virtual void executeAct(void) const = 0;
	const std::string &getTarget() const;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //FORM_HPP
