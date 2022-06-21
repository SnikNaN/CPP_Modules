#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	_name(name),
	_grade(grade)
{
	if (grade < _maxGrade)
		throw GradeTooHighException();
	else if (grade > _minGrade)
		throw GradeTooLowException();
	std::cout << "Created: " << *this << std::endl;
}

int Bureaucrat::getGrade() const
{
	return (_grade);
}

const std::string &Bureaucrat::getName() const
{
	return (_name);
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bcrat)
{
	os << bcrat.getName() << ", bureaucrat grade " << bcrat.getGrade() << ".";
	return (os);
}

Bureaucrat::Bureaucrat() :
	_name("Nobody"),
	_grade(_minGrade)
{}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destroyed: " << *this << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) :
	_name(copy._name),
	_grade(copy._grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	(void)other;
	return (*this);
}

void Bureaucrat::upGrade()
{
	std::cout << "Try to increment grade: " << *this << std::endl;
	if (_grade == _maxGrade)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << "Success: " << *this << std::endl;
}

void Bureaucrat::downGrade()
{
	std::cout << "Try to decrement grade: " << *this << std::endl;
	if (_grade == _minGrade)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << "Success: " << *this << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("BureaucratException: grade too high");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("BureaucratException: grade too low");
}

void	Bureaucrat::signForm(Form& form) const
{
	if (form.isSigned())
	{
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because it has been already signed" << std::endl;
		return;
	}
	if (_grade <= form.getGradeToSign())
		std::cout << _name << " signed " << form.getName() << std::endl;
	else
	{
		std::cout << _name << " couldn't sign " << form.getName()
			<< " because his grade is too low" << std::endl;
	}
	form.beSigned(*this);
}

void	Bureaucrat::executeForm(const Form& form) const
{
	if (!form.isSigned())
	{
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because it hasn't been signed yet" << std::endl;
		return;
	}
	if (_grade <= form.getGradeToExec())
		std::cout << _name << " executed " << form.getName() << std::endl;
	else
	{
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because his grade is too low" << std::endl;
	}
	form.execute(*this);
}