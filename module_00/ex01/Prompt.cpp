#include "Prompt.hpp"

Prompt::Prompt()
{
	working = true;
}

void	Prompt::read_command()
{
	std::string	cmd;
	bool		cmd_received(false);

	while (!cmd_received)
	{
		cmd_received = true;
		std::cout << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Enter a command: ADD, SEARCH or EXIT" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << ">> ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			phoneBook.add_contact();
		else if (cmd == "SEARCH")
			phoneBook.search_contact();
		else if (cmd == "EXIT")
			working = false;
		else if (std::cin.eof())
		{
			std::cout << std::endl << "stdin is closed... Exit..." << std::endl;
			exit(EXIT_FAILURE);
		}
		else
		{
			cmd_received = false;
			std::cout << "Wrong command!" << std::endl;
		}
	}
}

bool	Prompt::is_working() const
{
	return (working);
}