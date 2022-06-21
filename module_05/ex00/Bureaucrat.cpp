#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name),
															 _grade(grade)
{
	std::cout << "Try to create: " << *this << std::endl;
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

Bureaucrat::Bureaucrat() :	_name("Nobody"),
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

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &copy)
{
	_grade = copy._grade;
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
