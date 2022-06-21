#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include <iostream>
#include <string>

#include "Contact.hpp"

class PhoneBook
{
private:
	int		index;
	int 	amount;
	static const int capacity = 8;
	Contact	contacts[capacity];
public:
	PhoneBook();
	void show_info(void) const;
	void add_contact(void);
	void search_contact(void) const;
};

#endif