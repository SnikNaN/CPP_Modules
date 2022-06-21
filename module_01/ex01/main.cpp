#include "Zombie.hpp"

int	main(void)
{
	Zombie*		zombies;
	std::string	str;
	int 		cnt(0);

	while (cnt < 1 || cnt > 100)
	{
		std::cout << "input number of zombies (1 - 100):" << std::endl;
		std::getline(std::cin, str);
		cnt = std::atoi(str.c_str());
	}
	std::cout << "input name of zombies:" << std::endl;
	std::getline(std::cin, str);
	zombies = zombieHorde(cnt, str);
	for (int i = 0; i < cnt; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}