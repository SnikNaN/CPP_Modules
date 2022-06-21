#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
private:
	Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& copy);

	const static int	_minGrade = 150;
	const static int 	_maxGrade = 1;

	const std::string	_name;
	int					_grade;
public:
	Bureaucrat(const std::string &name, int grade);
	virtual ~Bureaucrat();
	Bureaucrat(const Bureaucrat& copy);

	class GradeTooHighException: public std::exception
	{
		const char* what() const throw();
	};
	class GradeTooLowException: public std::exception
	{
		const char* what() const throw();
	};

	const std::string	&getName() const;
	int			 		getGrade() const;

	void	upGrade();
	void	downGrade();
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bcrat);

#endif //BUREAUCRAT_HPP
