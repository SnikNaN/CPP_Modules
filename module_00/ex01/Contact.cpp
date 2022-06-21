#include "Contact.hpp"

std::string	Contact::fields_name[fields_num] =
	{
		"First name",
		"Last name",
		"Nikname",
		"Phone number",
		"Darkest secret"
	};

std::string Contact::get_field(int field) const
{
	std::string str;
	str = fields[field];
	return (str);
}

void Contact::set_field(int field, std::string str)
{
	fields[field] = str;
}

std::string Contact::get_field_name(int field) const
{
	std::string str;
	str = fields_name[field];
	return (str);
}
