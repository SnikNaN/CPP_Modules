#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "string"

class Contact
{
public:
	static const int fields_num = 5;
	void set_field(int field, std::string str);
	std::string get_field(int field) const;
	std::string get_field_name(int field) const;
private:
	std::string	fields[fields_num];
	static	std::string	fields_name[fields_num];
};

#endif