#ifndef PROMPT_HPP
#define PROMPT_HPP

#include "PhoneBook.hpp"

class Prompt
{
private:
	PhoneBook	phoneBook;
	bool		working;
public:
	Prompt();
	void read_command(void);
	bool is_working(void) const;
};

#endif