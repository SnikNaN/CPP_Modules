#include "Form.hpp"

Form::Form() :
	_name("Unknown Form"),
	_signed(false),
	_gradeToSign(150),
	_gradeToExec(150)
{}

const std::string &Form::getName() const
{
	return _name;
}

bool Form::isSigned() const
{
	return _signed;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExec() const
{
	return _gradeToExec;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

Form::~Form()
{
	std::cout << "Destroyed: " << *this << std::endl;
}

Form::Form(const Form& copy) :
	_name(copy._name),
	_signed(copy._signed),
	_gradeToSign(copy._gradeToSign),
	_gradeToExec(copy._gradeToExec)
{}

Form& Form::operator=(const Form &other)
{
	(void)other;
	return (*this);
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec) :
	_name(name),
	_signed(false),
	_gradeToSign(gradeToSign),
	_gradeToExec(gradeToExec)
{
	std::cout << "Try to create: " << *this << std::endl;
	if (gradeToSign < _maxGrade)
		throw GradeTooHighException();
	else if (gradeToSign > _minGrade)
		throw GradeTooLowException();
	if (gradeToExec < _maxGrade)
		throw GradeTooHighException();
	else if (gradeToExec > _minGrade)
		throw GradeTooLowException();
	std::cout << "Created: " << *this << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("FormException: grade too high");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("FormException: grade too low");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form name: " << form.getName()
		<< ", signed: " << (form.isSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign()
		<< ", grade to execute: " << form.getGradeToExec()
		<< ".";
	return (os);
}