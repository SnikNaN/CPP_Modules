#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

#include <iostream>

class Bureaucrat;

class Form
{
private:
	Form();
	Form& operator=(const Form& other);

	const static int	_minGrade = 150;
	const static int 	_maxGrade = 1;

	const std::string	_name;
	bool 				_signed;
	const int			_gradeToSign;
	const int			_gradeToExec;
public:
	Form(const std::string &name, int gradeToSign, int gradeToExec);
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
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif //FORM_HPP
