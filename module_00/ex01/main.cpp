#include "Prompt.hpp"

int	main(void)
{
	Prompt	prompt;
	while (prompt.is_working())
		prompt.read_command();
	std::cout << "-------" << std::endl;
	std::cout << "Exit..." << std::endl;
	std::cout << "-------" << std::endl;
	return (0);
}