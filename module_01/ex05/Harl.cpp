#include "Harl.hpp"

void Harl::debug() const
{
	std::cout << "Debug message" << std::endl;
}

void Harl::info() const
{
	std::cout << "Info message" << std::endl;
}

void Harl::warning() const
{
	std::cout << "Warning message" << std::endl;
}

void Harl::error() const
{
	std::cout << "Error message" << std::endl;
}

void Harl::complain(std::string level) const
{
	void	(Harl::* complaint[])(void) const =
		{
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
		};
	std::string complaintLvls[] =
		{
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
		};

	for (size_t i = 0; i < complaintLvls->length(); i++)
	{
		if (level == complaintLvls[i])
			(this->*complaint[i])();
	}
}