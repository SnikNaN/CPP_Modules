#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	index = 0;
	amount = 0;
}

void PhoneBook::add_contact()
{
	std::string	str;

	std::cout << "Input the following information for new contact:" << std::endl;
	for (int i = 0; i < contacts->fields_num; i++)
	{
		while (true)
		{
			std::cout << contacts->get_field_name(i) << ": ";
			std::getline(std::cin, str);
			if (std::cin.eof())
			{
				std::cout << std::endl << "stdin is closed... Exit..." << std::endl;
				exit(EXIT_FAILURE);
			}
			if (str.empty())
				std::cout << "Field can't be empty!" << std::endl;
			else
			{
				contacts[index].set_field(i, str);
				break;
			}
		}
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "New entry was created..." << std::endl;
	std::cout << "------------------------" << std::endl;
	index = (index + 1) % capacity;
	if (amount < capacity)
		amount++;
}

void PhoneBook::show_info(void) const
{
	std::cout << "*-----------------PHONEBOOK-----------------*" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|----------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < amount; i++)
	{
		std::cout << "|" << std::setw(10) << i + 1;
		for (int j = 0; j < 3; j++)
		{
			if (contacts[i].get_field(j).length() <= 10)
				std::cout << "|" << std::setw(10) << contacts[i].get_field(j);
			else
			{
				std::cout << "|" << contacts[i].get_field(j).substr(0, 9);
				std::cout << ".";
			}
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "*--------------------END--------------------*" << std::endl;
	std::cout << std::endl;
}

void PhoneBook::search_contact() const
{
	std::string	search;
	int			res;

	PhoneBook::show_info();
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Enter the index of the entry to display:" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << ">> ";
	std::getline(std::cin, search);
	res = std::atoi(search.c_str());
	if (res >= 1 && res <= amount)
		for (int i = 0; i < 5; i++)
		{
			std::cout << contacts->get_field_name(i) << ": ";
			std::cout << contacts[res - 1].get_field(i) << std::endl;
		}
	else
		std::cout << "=( Sorry, there is no contacts with this index" << std::endl;
}